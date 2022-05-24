// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Animation.serializer.h"

#include <algorithm>

#include "once.h"
#include "coded_stream.h"
#include "wire_format_lite_inl.h"
// @@protoc_insertion_point(includes)

namespace Serializer {

void protobuf_ShutdownFile_Animation_2eproto() {
  delete Curve::default_instance_;
}

void protobuf_AddDesc_Animation_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::Serializer::protobuf_AddDesc_Vector_2eproto();
  ::Serializer::protobuf_AddDesc_Color_2eproto();
  Curve::default_instance_ = new Curve();
  Curve::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Animation_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Animation_2eproto {
  StaticDescriptorInitializer_Animation_2eproto() {
    protobuf_AddDesc_Animation_2eproto();
  }
} static_descriptor_initializer_Animation_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int Curve::kKeyPointsFieldNumber;
#endif  // !_MSC_VER

Curve::Curve()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void Curve::InitAsDefaultInstance() {
}

Curve::Curve(const Curve& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void Curve::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Curve::~Curve() {
  SharedDtor();
}

void Curve::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Curve::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Curve& Curve::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Animation_2eproto();  return *default_instance_;
}

Curve* Curve::default_instance_ = NULL;

Curve* Curve::New() const {
  return new Curve;
}

void Curve::Clear() {
  keypoints_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Curve::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Serializer.Vector4f KeyPoints = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_KeyPoints:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_keypoints()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_KeyPoints;
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

void Curve::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Serializer.Vector4f KeyPoints = 1;
  for (int i = 0; i < this->keypoints_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->keypoints(i), output);
  }
  
}

int Curve::ByteSize() const {
  int total_size = 0;
  
  // repeated .Serializer.Vector4f KeyPoints = 1;
  total_size += 1 * this->keypoints_size();
  for (int i = 0; i < this->keypoints_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->keypoints(i));
  }
  
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Curve::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Curve*>(&from));
}

void Curve::MergeFrom(const Curve& from) {
  GOOGLE_CHECK_NE(&from, this);
  keypoints_.MergeFrom(from.keypoints_);
}

void Curve::CopyFrom(const Curve& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Curve::IsInitialized() const {
  
  for (int i = 0; i < keypoints_size(); i++) {
    if (!this->keypoints(i).IsInitialized()) return false;
  }
  return true;
}

void Curve::Swap(Curve* other) {
  if (other != this) {
    keypoints_.Swap(&other->keypoints_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string Curve::GetTypeName() const {
  return "Serializer.Curve";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Serializer

// @@protoc_insertion_point(global_scope)
