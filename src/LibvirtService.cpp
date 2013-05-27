#include <LibvirtService.h>
#include <ConfigConstants.h>
#include <Debug.h>
#include <Macros.h>

#include <iniparser.h>
#include <dictionary.h>

#include <libvirt/virterror.h>
#include <string>
#include <sstream>

string LibvirtService::connectionUrl = "";


LibvirtService::LibvirtService() : Service("Libvirt")
{
}

LibvirtService::~LibvirtService()
{
}

// Private methods

virDomainPtr LibvirtService::getDomainByName(const virConnectPtr conn, const string& name) throw (LibvirtException)
{
    virDomainPtr dom = virDomainLookupByName(conn, name.c_str());
    if (dom == NULL)
    {
        // throwError("Domain not found: " + name);
        // TODO: Verify we populate the right error
        throwLastKnownError(conn);
    }
    return dom;
}

DomainInfo LibvirtService::getDomainInfo(const virConnectPtr conn, const virDomainPtr domain) throw (LibvirtException)
{
    if (domain == NULL)
    {
        // TODO: verify we populate the right error
        throwLastKnownError(conn);
    }

    virDomainInfo info;
    if (virDomainGetInfo(domain, &info) < 0)
    {
        throwLastKnownError(conn);
    }

    const char *name = virDomainGetName(domain);
    if (name == NULL)
    {
        throwLastKnownError(conn);
    }

    DomainInfo domainInfo;
    domainInfo.name            = string(name);
    domainInfo.uuid            = "";                // TODO
    domainInfo.state           = toDomainState(info.state);        // the running state, one of virDomainState
    domainInfo.numberVirtCpu   = info.nrVirtCpu;    // the number of virtual CPUs for the domain 
    domainInfo.memory          = info.memory;       // the memory in KBytes used by the domain

    free((char*) name);
    return domainInfo;
}

DomainState::type LibvirtService::toDomainState(unsigned char state)
{
    switch (state)
    {
        case 1: return DomainState::ON;        break;
        case 2: return DomainState::OFF;       break;
        case 3: return DomainState::PAUSED;    break;
        case 4: return DomainState::UNKNOWN;   break;
        default: return DomainState::UNKNOWN;  break;
    }
}

LibvirtException LibvirtService::fromLibvirtError(const virErrorPtr error)
{
    LibvirtException exception;
    exception.code = error->code;
    exception.domain = error->domain;
    exception.msg = error->message == NULL? "" : string(error->message);
    exception.level = error->level;
    exception.str1 = error->str1 == NULL? "" : string(error->str1);
    exception.str2 = error->str2 == NULL? "" : string(error->str2);
    exception.str3 = error->str3 == NULL? "" : string(error->str3);
    exception.int1 = error->int1;
    exception.int2 = error->int2;
    return exception;
}

// Public methods

bool LibvirtService::initialize(dictionary* configuration)
{
    if (LibvirtService::connectionUrl.empty())
    {
        LibvirtService::connectionUrl = getStringProperty(configuration, monitorUri);
    }

    return !LibvirtService::connectionUrl.empty();
}

bool LibvirtService::start()
{
    return true;
}

bool LibvirtService::stop()
{
    return true;
}

bool LibvirtService::cleanup()
{
    return true;
}

void LibvirtService::throwLastKnownError(const virConnectPtr conn)
{
    virErrorPtr error = virConnGetLastError(conn);
    throw fromLibvirtError(error);
}

virConnectPtr LibvirtService::connect() throw (LibvirtException)
{
    virConnectPtr conn = virConnectOpen(LibvirtService::connectionUrl.c_str());
    if (conn == NULL)
    {
        LibvirtException exception;
        exception.code = -1; // Connection error code
        exception.msg = "Could not connect to " + LibvirtService::connectionUrl;
        throw exception;
    }
    return conn;
}

void LibvirtService::disconnect(const virConnectPtr conn)
{
    if (virConnectClose(conn) < 0)
    {
        LOG(("Error closing connection: " + LibvirtService::connectionUrl).c_str());
    }
}

void LibvirtService::getNodeInfo(NodeInfo& _return, const virConnectPtr conn) throw (LibvirtException)
{
    virNodeInfo info;

    if (virNodeGetInfo(conn, &info) < 0)
    {
        throwLastKnownError(conn);
    }

    _return.cores   = info.cores;    // number of cores per socket
    _return.sockets = info.sockets;  // number of CPU sockets per node
    _return.memory  = info.memory;   // memory size in kilobytes
}

// Adapted from http://builder.virt-tools.org/artifacts/libvirt-appdev-guide/html/Application_Development_Guide-Guest_Domains-Listing.html
void LibvirtService::getDomains(std::vector<DomainInfo> & _return, const virConnectPtr conn) throw (LibvirtException)
{
    int numActiveDomains = virConnectNumOfDomains(conn);
    if (numActiveDomains > 0)
    {
        int *activeDomains = (int*) malloc(sizeof(int) * numActiveDomains);
        numActiveDomains = virConnectListDomains(conn, activeDomains, numActiveDomains);

        for (int i = 0; i < numActiveDomains; i++)
        {
            virDomainPtr domain = virDomainLookupByID(conn, activeDomains[i]);
                
            if (domain != NULL)
            {
                try
                {
                    _return.push_back(getDomainInfo(conn, domain));
                    virDomainFree(domain);
                }
                catch (...)
                {
                    virDomainFree(domain);
                }
            }
        }

        free(activeDomains);
    }
    // TODO else => throwError?

    int numInactiveDomains = virConnectNumOfDefinedDomains(conn);
    if (numInactiveDomains > 0)
    {
        char **inactiveDomains = (char**) malloc(sizeof(char *) * numInactiveDomains);
        numInactiveDomains = virConnectListDefinedDomains(conn, inactiveDomains, numInactiveDomains);

        for (int i = 0; i < numInactiveDomains; i++)
        {
            virDomainPtr domain = virDomainLookupByName(conn, inactiveDomains[i]);
        
            if (domain != NULL)
            {
                try
                {
                    _return.push_back(getDomainInfo(conn, domain));
                    virDomainFree(domain);
                }
                catch (...)
                {
                    virDomainFree(domain);
                }
            }

            free(inactiveDomains[i]);
        }

        free(inactiveDomains);
    }
    // TODO else => throwError?
}

void LibvirtService::defineDomain(const virConnectPtr conn, const std::string& xmlDesc) throw (LibvirtException)
{
    virDomainPtr domain = virDomainDefineXML(conn, xmlDesc.c_str());

    if (domain == NULL)
    {
        throwLastKnownError(conn);
    }

    virDomainFree(domain);
}

void LibvirtService::undefineDomain(const virConnectPtr conn, const std::string& domainName) throw (LibvirtException)
{
    virDomainPtr domain = getDomainByName(conn, domainName);

    int ret = virDomainUndefine(domain);
    virDomainFree(domain);

    if (ret < 0)
    {
        throwLastKnownError(conn);
    }
}

bool LibvirtService::existDomain(const virConnectPtr conn, const std::string& domainName)
{
    try
    {
        virDomainPtr domain = getDomainByName(conn, domainName);
        virDomainFree(domain);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

DomainState::type LibvirtService::getDomainState(const virConnectPtr conn, const std::string& domainName) throw (LibvirtException)
{
    virDomainPtr domain = getDomainByName(conn, domainName);
    virDomainInfo info;

    if (virDomainGetInfo(domain, &info) < 0)
    {
        virDomainFree(domain);
        throwLastKnownError(conn);
    }

    DomainState::type result = toDomainState(info.state);

    virDomainFree(domain);

    return result;
}

void LibvirtService::getDomainInfo(DomainInfo& _return, const virConnectPtr conn, const std::string& domainName) throw (LibvirtException)
{
    virDomainPtr domain = getDomainByName(conn, domainName);
    
    try
    {
        _return = getDomainInfo(conn, domain);
        virDomainFree(domain);
    }
    catch (LibvirtException exception)
    {
        virDomainFree(domain);
        throw exception;
    }
}

void LibvirtService::powerOn(const virConnectPtr conn, const std::string& domainName) throw (LibvirtException)
{
    virDomainPtr domain = getDomainByName(conn, domainName);

    int ret = virDomainCreate(domain);
    virDomainFree(domain);
    
    if (ret < 0)
    {
        throwLastKnownError(conn);
    }   
}

void LibvirtService::powerOff(const virConnectPtr conn, const std::string& domainName) throw (LibvirtException)
{
    virDomainPtr domain = getDomainByName(conn, domainName);

    int ret = virDomainDestroy(domain);
    virDomainFree(domain);
    
    if (ret < 0)
    {
        throwLastKnownError(conn);
    }
}

void LibvirtService::reset(const virConnectPtr conn, const std::string& domainName) throw (LibvirtException)
{
    virDomainPtr domain = getDomainByName(conn, domainName);

    int ret = virDomainReboot(domain, 0);
    virDomainFree(domain);
    
    if (ret < 0)
    {
        throwLastKnownError(conn);
    }
}

void LibvirtService::pause(const virConnectPtr conn, const std::string& domainName) throw (LibvirtException)
{
    virDomainPtr domain = getDomainByName(conn, domainName);

    int ret = virDomainSuspend(domain);
    virDomainFree(domain);
    
    if (ret < 0)
    {
        throwLastKnownError(conn);
    }
}

void LibvirtService::resume(const virConnectPtr conn, const std::string& domainName) throw (LibvirtException)
{
    virDomainPtr domain = getDomainByName(conn, domainName);

    int ret = virDomainResume(domain);
    virDomainFree(domain);
    
    if (ret < 0)
    {
        throwLastKnownError(conn);
    }
}

void LibvirtService::createStoragePool(const virConnectPtr conn, const std::string& xmlDesc) throw (LibvirtException)
{
    virStoragePoolPtr storagePool = virStoragePoolCreateXML(conn, xmlDesc.c_str(), 0);
    if (storagePool == NULL)
    {
        throwLastKnownError(conn);
    }

    virStoragePoolFree(storagePool);
}

void LibvirtService::resizeDisk(const virConnectPtr conn, const string& domainName, const string& diskPath, const double diskSizeInKb) throw (LibvirtException)
{
    virDomainPtr dom = getDomainByName(conn, domainName);

    int result = virDomainBlockResize(dom, diskPath.c_str(), diskSizeInKb, 0);
    if (result < 0)
    {
        throwLastKnownError(conn);
    }

    virDomainFree(dom);
}

