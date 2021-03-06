// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Prefab.txt.serializer.h"

#include <algorithm>

#include "once.h"
#include "coded_stream.h"
#include "wire_format_lite_inl.h"
// @@protoc_insertion_point(includes)

namespace XiaoHua {

void protobuf_ShutdownFile_Prefab_2etxt() {
  delete Prefab::default_instance_;
}

void protobuf_AddDesc_Prefab_2etxt() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  Prefab::default_instance_ = new Prefab();
  Prefab::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Prefab_2etxt);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Prefab_2etxt {
  StaticDescriptorInitializer_Prefab_2etxt() {
    protobuf_AddDesc_Prefab_2etxt();
  }
} static_descriptor_initializer_Prefab_2etxt_;


// ===================================================================

#ifndef _MSC_VER
const int Prefab::kNameFieldNumber;
const int Prefab::kLayerFieldNumber;
#endif  // !_MSC_VER

Prefab::Prefab()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void Prefab::InitAsDefaultInstance() {
}

Prefab::Prefab(const Prefab& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void Prefab::SharedCtor() {
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  layer_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Prefab::~Prefab() {
  SharedDtor();
}

void Prefab::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void Prefab::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Prefab& Prefab::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Prefab_2etxt();  return *default_instance_;
}

Prefab* Prefab::default_instance_ = NULL;

Prefab* Prefab::New() const {
  return new Prefab;
}

void Prefab::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    layer_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Prefab::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string name = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_layer;
        break;
      }
      
      // optional int32 layer = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_layer:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &layer_)));
          set_has_layer();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Prefab::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->name(), output);
  }
  
  // optional int32 layer = 2;
  if (has_layer()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->layer(), output);
  }
  
}

int Prefab::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }
    
    // optional int32 layer = 2;
    if (has_layer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->layer());
    }
    
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Prefab::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Prefab*>(&from));
}

void Prefab::MergeFrom(const Prefab& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_layer()) {
      set_layer(from.layer());
    }
  }
}

void Prefab::CopyFrom(const Prefab& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Prefab::IsInitialized() const {
  
  return true;
}

void Prefab::Swap(Prefab* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(layer_, other->layer_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string Prefab::GetTypeName() const {
  return "XiaoHua.Prefab";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace XiaoHua

// @@protoc_insertion_point(global_scope)
