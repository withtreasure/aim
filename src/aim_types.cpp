/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "aim_types.h"

#include <algorithm>



int _kDomainStateValues[] = {
  DomainState::ON,
  DomainState::OFF,
  DomainState::PAUSED,
  DomainState::UNKNOWN
};
const char* _kDomainStateNames[] = {
  "ON",
  "OFF",
  "PAUSED",
  "UNKNOWN"
};
const std::map<int, const char*> _DomainState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kDomainStateValues, _kDomainStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

const char* Datastore::ascii_fingerprint = "E2396C406CD75CE894E195C727905C26";
const uint8_t Datastore::binary_fingerprint[16] = {0xE2,0x39,0x6C,0x40,0x6C,0xD7,0x5C,0xE8,0x94,0xE1,0x95,0xC7,0x27,0x90,0x5C,0x26};

uint32_t Datastore::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->device);
          this->__isset.device = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->path);
          this->__isset.path = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->type);
          this->__isset.type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->totalSize);
          this->__isset.totalSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->usableSize);
          this->__isset.usableSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Datastore::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Datastore");

  xfer += oprot->writeFieldBegin("device", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->device);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("path", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->path);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("totalSize", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->totalSize);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("usableSize", ::apache::thrift::protocol::T_I64, 5);
  xfer += oprot->writeI64(this->usableSize);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Datastore &a, Datastore &b) {
  using ::std::swap;
  swap(a.device, b.device);
  swap(a.path, b.path);
  swap(a.type, b.type);
  swap(a.totalSize, b.totalSize);
  swap(a.usableSize, b.usableSize);
  swap(a.__isset, b.__isset);
}

const char* NetInterface::ascii_fingerprint = "AB879940BD15B6B25691265F7384B271";
const uint8_t NetInterface::binary_fingerprint[16] = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

uint32_t NetInterface::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->address);
          this->__isset.address = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->physicalAddress);
          this->__isset.physicalAddress = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NetInterface::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("NetInterface");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("address", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->address);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("physicalAddress", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->physicalAddress);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NetInterface &a, NetInterface &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.address, b.address);
  swap(a.physicalAddress, b.physicalAddress);
  swap(a.__isset, b.__isset);
}

const char* NodeInfo::ascii_fingerprint = "996F8E61E9CD3215A74A626B695C616B";
const uint8_t NodeInfo::binary_fingerprint[16] = {0x99,0x6F,0x8E,0x61,0xE9,0xCD,0x32,0x15,0xA7,0x4A,0x62,0x6B,0x69,0x5C,0x61,0x6B};

uint32_t NodeInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->version);
          this->__isset.version = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->cores);
          this->__isset.cores = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->sockets);
          this->__isset.sockets = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->memory);
          this->__isset.memory = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NodeInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("NodeInfo");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("version", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->version);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cores", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->cores);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sockets", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->sockets);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("memory", ::apache::thrift::protocol::T_DOUBLE, 5);
  xfer += oprot->writeDouble(this->memory);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NodeInfo &a, NodeInfo &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.version, b.version);
  swap(a.cores, b.cores);
  swap(a.sockets, b.sockets);
  swap(a.memory, b.memory);
  swap(a.__isset, b.__isset);
}

const char* DomainInfo::ascii_fingerprint = "A34937417D74BC5CE66DFE14D1CF9220";
const uint8_t DomainInfo::binary_fingerprint[16] = {0xA3,0x49,0x37,0x41,0x7D,0x74,0xBC,0x5C,0xE6,0x6D,0xFE,0x14,0xD1,0xCF,0x92,0x20};

uint32_t DomainInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->uuid);
          this->__isset.uuid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->state = (DomainState::type)ecast0;
          this->__isset.state = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->numberVirtCpu);
          this->__isset.numberVirtCpu = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->memory);
          this->__isset.memory = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->xmlDesc);
          this->__isset.xmlDesc = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DomainInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("DomainInfo");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("uuid", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->uuid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("state", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)this->state);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("numberVirtCpu", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->numberVirtCpu);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("memory", ::apache::thrift::protocol::T_DOUBLE, 5);
  xfer += oprot->writeDouble(this->memory);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("xmlDesc", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->xmlDesc);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DomainInfo &a, DomainInfo &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.uuid, b.uuid);
  swap(a.state, b.state);
  swap(a.numberVirtCpu, b.numberVirtCpu);
  swap(a.memory, b.memory);
  swap(a.xmlDesc, b.xmlDesc);
  swap(a.__isset, b.__isset);
}

const char* Datapoint::ascii_fingerprint = "9C2A05F173B50306037BDE9AE30E1B99";
const uint8_t Datapoint::binary_fingerprint[16] = {0x9C,0x2A,0x05,0xF1,0x73,0xB5,0x03,0x06,0x03,0x7B,0xDE,0x9A,0xE3,0x0E,0x1B,0x99};

uint32_t Datapoint::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->timestamp);
          this->__isset.timestamp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Datapoint::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Datapoint");

  xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->timestamp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Datapoint &a, Datapoint &b) {
  using ::std::swap;
  swap(a.timestamp, b.timestamp);
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

const char* Measure::ascii_fingerprint = "0B28A7DB51DEEB464CE586F13C2EC47D";
const uint8_t Measure::binary_fingerprint[16] = {0x0B,0x28,0xA7,0xDB,0x51,0xDE,0xEB,0x46,0x4C,0xE5,0x86,0xF1,0x3C,0x2E,0xC4,0x7D};

uint32_t Measure::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->metric);
          this->__isset.metric = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->datapoints.clear();
            uint32_t _size1;
            ::apache::thrift::protocol::TType _etype4;
            xfer += iprot->readListBegin(_etype4, _size1);
            this->datapoints.resize(_size1);
            uint32_t _i5;
            for (_i5 = 0; _i5 < _size1; ++_i5)
            {
              xfer += this->datapoints[_i5].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.datapoints = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->dimensions.clear();
            uint32_t _size6;
            ::apache::thrift::protocol::TType _ktype7;
            ::apache::thrift::protocol::TType _vtype8;
            xfer += iprot->readMapBegin(_ktype7, _vtype8, _size6);
            uint32_t _i10;
            for (_i10 = 0; _i10 < _size6; ++_i10)
            {
              std::string _key11;
              xfer += iprot->readString(_key11);
              std::string& _val12 = this->dimensions[_key11];
              xfer += iprot->readString(_val12);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.dimensions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Measure::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Measure");

  xfer += oprot->writeFieldBegin("metric", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->metric);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("datapoints", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->datapoints.size()));
    std::vector<Datapoint> ::const_iterator _iter13;
    for (_iter13 = this->datapoints.begin(); _iter13 != this->datapoints.end(); ++_iter13)
    {
      xfer += (*_iter13).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dimensions", ::apache::thrift::protocol::T_MAP, 3);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->dimensions.size()));
    std::map<std::string, std::string> ::const_iterator _iter14;
    for (_iter14 = this->dimensions.begin(); _iter14 != this->dimensions.end(); ++_iter14)
    {
      xfer += oprot->writeString(_iter14->first);
      xfer += oprot->writeString(_iter14->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Measure &a, Measure &b) {
  using ::std::swap;
  swap(a.metric, b.metric);
  swap(a.datapoints, b.datapoints);
  swap(a.dimensions, b.dimensions);
  swap(a.__isset, b.__isset);
}

const char* DomainBlockInfo::ascii_fingerprint = "4A712C500E54918CFBA57A70D875BC7B";
const uint8_t DomainBlockInfo::binary_fingerprint[16] = {0x4A,0x71,0x2C,0x50,0x0E,0x54,0x91,0x8C,0xFB,0xA5,0x7A,0x70,0xD8,0x75,0xBC,0x7B};

uint32_t DomainBlockInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->capacity);
          this->__isset.capacity = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->allocation);
          this->__isset.allocation = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->physical);
          this->__isset.physical = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->diskPath);
          this->__isset.diskPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DomainBlockInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("DomainBlockInfo");

  xfer += oprot->writeFieldBegin("capacity", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->capacity);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("allocation", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->allocation);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("physical", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->physical);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("diskPath", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->diskPath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DomainBlockInfo &a, DomainBlockInfo &b) {
  using ::std::swap;
  swap(a.capacity, b.capacity);
  swap(a.allocation, b.allocation);
  swap(a.physical, b.physical);
  swap(a.diskPath, b.diskPath);
  swap(a.__isset, b.__isset);
}

const char* RimpException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t RimpException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t RimpException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RimpException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("RimpException");

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RimpException &a, RimpException &b) {
  using ::std::swap;
  swap(a.description, b.description);
  swap(a.__isset, b.__isset);
}

const char* VLanException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t VLanException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t VLanException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t VLanException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("VLanException");

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(VLanException &a, VLanException &b) {
  using ::std::swap;
  swap(a.description, b.description);
  swap(a.__isset, b.__isset);
}

const char* StorageException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t StorageException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t StorageException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t StorageException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("StorageException");

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StorageException &a, StorageException &b) {
  using ::std::swap;
  swap(a.description, b.description);
  swap(a.__isset, b.__isset);
}

const char* LibvirtException::ascii_fingerprint = "65C3F5292FCE4322B50FAA63577642EC";
const uint8_t LibvirtException::binary_fingerprint[16] = {0x65,0xC3,0xF5,0x29,0x2F,0xCE,0x43,0x22,0xB5,0x0F,0xAA,0x63,0x57,0x76,0x42,0xEC};

uint32_t LibvirtException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->code);
          this->__isset.code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->domain);
          this->__isset.domain = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg);
          this->__isset.msg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->level);
          this->__isset.level = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->str1);
          this->__isset.str1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->str2);
          this->__isset.str2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->str3);
          this->__isset.str3 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->int1);
          this->__isset.int1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->int2);
          this->__isset.int2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t LibvirtException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("LibvirtException");

  xfer += oprot->writeFieldBegin("code", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->code);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("domain", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->domain);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("msg", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->msg);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("level", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->level);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("str1", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->str1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("str2", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->str2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("str3", ::apache::thrift::protocol::T_STRING, 7);
  xfer += oprot->writeString(this->str3);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("int1", ::apache::thrift::protocol::T_I32, 8);
  xfer += oprot->writeI32(this->int1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("int2", ::apache::thrift::protocol::T_I32, 9);
  xfer += oprot->writeI32(this->int2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(LibvirtException &a, LibvirtException &b) {
  using ::std::swap;
  swap(a.code, b.code);
  swap(a.domain, b.domain);
  swap(a.msg, b.msg);
  swap(a.level, b.level);
  swap(a.str1, b.str1);
  swap(a.str2, b.str2);
  swap(a.str3, b.str3);
  swap(a.int1, b.int1);
  swap(a.int2, b.int2);
  swap(a.__isset, b.__isset);
}


