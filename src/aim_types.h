/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef aim_TYPES_H
#define aim_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>





struct DomainState {
  enum type {
    ON = 1,
    OFF = 2,
    PAUSED = 3,
    UNKNOWN = 4
  };
};

extern const std::map<int, const char*> _DomainState_VALUES_TO_NAMES;

typedef struct _Datastore__isset {
  _Datastore__isset() : device(false), path(false), type(false), totalSize(false), usableSize(false) {}
  bool device;
  bool path;
  bool type;
  bool totalSize;
  bool usableSize;
} _Datastore__isset;

class Datastore {
 public:

  static const char* ascii_fingerprint; // = "E2396C406CD75CE894E195C727905C26";
  static const uint8_t binary_fingerprint[16]; // = {0xE2,0x39,0x6C,0x40,0x6C,0xD7,0x5C,0xE8,0x94,0xE1,0x95,0xC7,0x27,0x90,0x5C,0x26};

  Datastore() : device(), path(), type(), totalSize(0), usableSize(0) {
  }

  virtual ~Datastore() throw() {}

  std::string device;
  std::string path;
  std::string type;
  int64_t totalSize;
  int64_t usableSize;

  _Datastore__isset __isset;

  void __set_device(const std::string& val) {
    device = val;
  }

  void __set_path(const std::string& val) {
    path = val;
  }

  void __set_type(const std::string& val) {
    type = val;
  }

  void __set_totalSize(const int64_t val) {
    totalSize = val;
  }

  void __set_usableSize(const int64_t val) {
    usableSize = val;
  }

  bool operator == (const Datastore & rhs) const
  {
    if (!(device == rhs.device))
      return false;
    if (!(path == rhs.path))
      return false;
    if (!(type == rhs.type))
      return false;
    if (!(totalSize == rhs.totalSize))
      return false;
    if (!(usableSize == rhs.usableSize))
      return false;
    return true;
  }
  bool operator != (const Datastore &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Datastore & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Datastore &a, Datastore &b);

typedef struct _NetInterface__isset {
  _NetInterface__isset() : name(false), address(false), physicalAddress(false) {}
  bool name;
  bool address;
  bool physicalAddress;
} _NetInterface__isset;

class NetInterface {
 public:

  static const char* ascii_fingerprint; // = "AB879940BD15B6B25691265F7384B271";
  static const uint8_t binary_fingerprint[16]; // = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

  NetInterface() : name(), address(), physicalAddress() {
  }

  virtual ~NetInterface() throw() {}

  std::string name;
  std::string address;
  std::string physicalAddress;

  _NetInterface__isset __isset;

  void __set_name(const std::string& val) {
    name = val;
  }

  void __set_address(const std::string& val) {
    address = val;
  }

  void __set_physicalAddress(const std::string& val) {
    physicalAddress = val;
  }

  bool operator == (const NetInterface & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(address == rhs.address))
      return false;
    if (!(physicalAddress == rhs.physicalAddress))
      return false;
    return true;
  }
  bool operator != (const NetInterface &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NetInterface & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(NetInterface &a, NetInterface &b);

typedef struct _NodeInfo__isset {
  _NodeInfo__isset() : name(false), version(false), cores(false), sockets(false), memory(false) {}
  bool name;
  bool version;
  bool cores;
  bool sockets;
  bool memory;
} _NodeInfo__isset;

class NodeInfo {
 public:

  static const char* ascii_fingerprint; // = "996F8E61E9CD3215A74A626B695C616B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x6F,0x8E,0x61,0xE9,0xCD,0x32,0x15,0xA7,0x4A,0x62,0x6B,0x69,0x5C,0x61,0x6B};

  NodeInfo() : name(), version(0), cores(0), sockets(0), memory(0) {
  }

  virtual ~NodeInfo() throw() {}

  std::string name;
  int64_t version;
  int32_t cores;
  int32_t sockets;
  double memory;

  _NodeInfo__isset __isset;

  void __set_name(const std::string& val) {
    name = val;
  }

  void __set_version(const int64_t val) {
    version = val;
  }

  void __set_cores(const int32_t val) {
    cores = val;
  }

  void __set_sockets(const int32_t val) {
    sockets = val;
  }

  void __set_memory(const double val) {
    memory = val;
  }

  bool operator == (const NodeInfo & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(version == rhs.version))
      return false;
    if (!(cores == rhs.cores))
      return false;
    if (!(sockets == rhs.sockets))
      return false;
    if (!(memory == rhs.memory))
      return false;
    return true;
  }
  bool operator != (const NodeInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NodeInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(NodeInfo &a, NodeInfo &b);

typedef struct _DomainInfo__isset {
  _DomainInfo__isset() : name(false), uuid(false), state(false), numberVirtCpu(false), memory(false), xmlDesc(false) {}
  bool name;
  bool uuid;
  bool state;
  bool numberVirtCpu;
  bool memory;
  bool xmlDesc;
} _DomainInfo__isset;

class DomainInfo {
 public:

  static const char* ascii_fingerprint; // = "A34937417D74BC5CE66DFE14D1CF9220";
  static const uint8_t binary_fingerprint[16]; // = {0xA3,0x49,0x37,0x41,0x7D,0x74,0xBC,0x5C,0xE6,0x6D,0xFE,0x14,0xD1,0xCF,0x92,0x20};

  DomainInfo() : name(), uuid(), state((DomainState::type)0), numberVirtCpu(0), memory(0), xmlDesc() {
  }

  virtual ~DomainInfo() throw() {}

  std::string name;
  std::string uuid;
  DomainState::type state;
  int32_t numberVirtCpu;
  double memory;
  std::string xmlDesc;

  _DomainInfo__isset __isset;

  void __set_name(const std::string& val) {
    name = val;
  }

  void __set_uuid(const std::string& val) {
    uuid = val;
  }

  void __set_state(const DomainState::type val) {
    state = val;
  }

  void __set_numberVirtCpu(const int32_t val) {
    numberVirtCpu = val;
  }

  void __set_memory(const double val) {
    memory = val;
  }

  void __set_xmlDesc(const std::string& val) {
    xmlDesc = val;
  }

  bool operator == (const DomainInfo & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(uuid == rhs.uuid))
      return false;
    if (!(state == rhs.state))
      return false;
    if (!(numberVirtCpu == rhs.numberVirtCpu))
      return false;
    if (!(memory == rhs.memory))
      return false;
    if (!(xmlDesc == rhs.xmlDesc))
      return false;
    return true;
  }
  bool operator != (const DomainInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DomainInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(DomainInfo &a, DomainInfo &b);

typedef struct _Datapoint__isset {
  _Datapoint__isset() : timestamp(false), value(false) {}
  bool timestamp;
  bool value;
} _Datapoint__isset;

class Datapoint {
 public:

  static const char* ascii_fingerprint; // = "9C2A05F173B50306037BDE9AE30E1B99";
  static const uint8_t binary_fingerprint[16]; // = {0x9C,0x2A,0x05,0xF1,0x73,0xB5,0x03,0x06,0x03,0x7B,0xDE,0x9A,0xE3,0x0E,0x1B,0x99};

  Datapoint() : timestamp(0), value(0) {
  }

  virtual ~Datapoint() throw() {}

  int32_t timestamp;
  int64_t value;

  _Datapoint__isset __isset;

  void __set_timestamp(const int32_t val) {
    timestamp = val;
  }

  void __set_value(const int64_t val) {
    value = val;
  }

  bool operator == (const Datapoint & rhs) const
  {
    if (!(timestamp == rhs.timestamp))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const Datapoint &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Datapoint & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Datapoint &a, Datapoint &b);

typedef struct _Measure__isset {
  _Measure__isset() : metric(false), datapoints(false) {}
  bool metric;
  bool datapoints;
} _Measure__isset;

class Measure {
 public:

  static const char* ascii_fingerprint; // = "64A25FF614B1FACF48B494E4EFA5EED7";
  static const uint8_t binary_fingerprint[16]; // = {0x64,0xA2,0x5F,0xF6,0x14,0xB1,0xFA,0xCF,0x48,0xB4,0x94,0xE4,0xEF,0xA5,0xEE,0xD7};

  Measure() : metric() {
  }

  virtual ~Measure() throw() {}

  std::string metric;
  std::vector<Datapoint>  datapoints;

  _Measure__isset __isset;

  void __set_metric(const std::string& val) {
    metric = val;
  }

  void __set_datapoints(const std::vector<Datapoint> & val) {
    datapoints = val;
  }

  bool operator == (const Measure & rhs) const
  {
    if (!(metric == rhs.metric))
      return false;
    if (!(datapoints == rhs.datapoints))
      return false;
    return true;
  }
  bool operator != (const Measure &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Measure & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Measure &a, Measure &b);

typedef struct _RimpException__isset {
  _RimpException__isset() : description(false) {}
  bool description;
} _RimpException__isset;

class RimpException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  RimpException() : description() {
  }

  virtual ~RimpException() throw() {}

  std::string description;

  _RimpException__isset __isset;

  void __set_description(const std::string& val) {
    description = val;
  }

  bool operator == (const RimpException & rhs) const
  {
    if (!(description == rhs.description))
      return false;
    return true;
  }
  bool operator != (const RimpException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RimpException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(RimpException &a, RimpException &b);

typedef struct _VLanException__isset {
  _VLanException__isset() : description(false) {}
  bool description;
} _VLanException__isset;

class VLanException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  VLanException() : description() {
  }

  virtual ~VLanException() throw() {}

  std::string description;

  _VLanException__isset __isset;

  void __set_description(const std::string& val) {
    description = val;
  }

  bool operator == (const VLanException & rhs) const
  {
    if (!(description == rhs.description))
      return false;
    return true;
  }
  bool operator != (const VLanException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const VLanException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(VLanException &a, VLanException &b);

typedef struct _StorageException__isset {
  _StorageException__isset() : description(false) {}
  bool description;
} _StorageException__isset;

class StorageException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  StorageException() : description() {
  }

  virtual ~StorageException() throw() {}

  std::string description;

  _StorageException__isset __isset;

  void __set_description(const std::string& val) {
    description = val;
  }

  bool operator == (const StorageException & rhs) const
  {
    if (!(description == rhs.description))
      return false;
    return true;
  }
  bool operator != (const StorageException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StorageException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(StorageException &a, StorageException &b);

typedef struct _LibvirtException__isset {
  _LibvirtException__isset() : code(false), domain(false), msg(false), level(false), str1(false), str2(false), str3(false), int1(false), int2(false) {}
  bool code;
  bool domain;
  bool msg;
  bool level;
  bool str1;
  bool str2;
  bool str3;
  bool int1;
  bool int2;
} _LibvirtException__isset;

class LibvirtException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "65C3F5292FCE4322B50FAA63577642EC";
  static const uint8_t binary_fingerprint[16]; // = {0x65,0xC3,0xF5,0x29,0x2F,0xCE,0x43,0x22,0xB5,0x0F,0xAA,0x63,0x57,0x76,0x42,0xEC};

  LibvirtException() : code(0), domain(0), msg(), level(0), str1(), str2(), str3(), int1(0), int2(0) {
  }

  virtual ~LibvirtException() throw() {}

  int32_t code;
  int32_t domain;
  std::string msg;
  int32_t level;
  std::string str1;
  std::string str2;
  std::string str3;
  int32_t int1;
  int32_t int2;

  _LibvirtException__isset __isset;

  void __set_code(const int32_t val) {
    code = val;
  }

  void __set_domain(const int32_t val) {
    domain = val;
  }

  void __set_msg(const std::string& val) {
    msg = val;
  }

  void __set_level(const int32_t val) {
    level = val;
  }

  void __set_str1(const std::string& val) {
    str1 = val;
  }

  void __set_str2(const std::string& val) {
    str2 = val;
  }

  void __set_str3(const std::string& val) {
    str3 = val;
  }

  void __set_int1(const int32_t val) {
    int1 = val;
  }

  void __set_int2(const int32_t val) {
    int2 = val;
  }

  bool operator == (const LibvirtException & rhs) const
  {
    if (!(code == rhs.code))
      return false;
    if (!(domain == rhs.domain))
      return false;
    if (!(msg == rhs.msg))
      return false;
    if (!(level == rhs.level))
      return false;
    if (!(str1 == rhs.str1))
      return false;
    if (!(str2 == rhs.str2))
      return false;
    if (!(str3 == rhs.str3))
      return false;
    if (!(int1 == rhs.int1))
      return false;
    if (!(int2 == rhs.int2))
      return false;
    return true;
  }
  bool operator != (const LibvirtException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LibvirtException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(LibvirtException &a, LibvirtException &b);



#endif
