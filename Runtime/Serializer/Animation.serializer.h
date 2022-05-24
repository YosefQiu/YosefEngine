// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Animation.proto

#ifndef PROTOBUF_Animation_2eproto__INCLUDED
#define PROTOBUF_Animation_2eproto__INCLUDED

#include <string>

#include "common.h"

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include "generated_message_util.h"
#include "repeated_field.h"
#include "extension_set.h"
#include "Vector.serializer.h"
#include "Color.serializer.h"
// @@protoc_insertion_point(includes)

namespace Serializer {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Animation_2eproto();
void protobuf_AssignDesc_Animation_2eproto();
void protobuf_ShutdownFile_Animation_2eproto();

class Curve;

// ===================================================================

class Curve : public ::google::protobuf::MessageLite {
 public:
  Curve();
  virtual ~Curve();
  
  Curve(const Curve& from);
  
  inline Curve& operator=(const Curve& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const Curve& default_instance();
  
  void Swap(Curve* other);
  
  // implements Message ----------------------------------------------
  
  Curve* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Curve& from);
  void MergeFrom(const Curve& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::std::string GetTypeName() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // repeated .Serializer.Vector4f KeyPoints = 1;
  inline int keypoints_size() const;
  inline void clear_keypoints();
  static const int kKeyPointsFieldNumber = 1;
  inline const ::Serializer::Vector4f& keypoints(int index) const;
  inline ::Serializer::Vector4f* mutable_keypoints(int index);
  inline ::Serializer::Vector4f* add_keypoints();
  inline const ::google::protobuf::RepeatedPtrField< ::Serializer::Vector4f >&
      keypoints() const;
  inline ::google::protobuf::RepeatedPtrField< ::Serializer::Vector4f >*
      mutable_keypoints();
  
  // @@protoc_insertion_point(class_scope:Serializer.Curve)
 private:
  
  ::google::protobuf::RepeatedPtrField< ::Serializer::Vector4f > keypoints_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_Animation_2eproto();
  friend void protobuf_AssignDesc_Animation_2eproto();
  friend void protobuf_ShutdownFile_Animation_2eproto();
  
  void InitAsDefaultInstance();
  static Curve* default_instance_;
};
// ===================================================================


// ===================================================================

// Curve

// repeated .Serializer.Vector4f KeyPoints = 1;
inline int Curve::keypoints_size() const {
  return keypoints_.size();
}
inline void Curve::clear_keypoints() {
  keypoints_.Clear();
}
inline const ::Serializer::Vector4f& Curve::keypoints(int index) const {
  return keypoints_.Get(index);
}
inline ::Serializer::Vector4f* Curve::mutable_keypoints(int index) {
  return keypoints_.Mutable(index);
}
inline ::Serializer::Vector4f* Curve::add_keypoints() {
  return keypoints_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Serializer::Vector4f >&
Curve::keypoints() const {
  return keypoints_;
}
inline ::google::protobuf::RepeatedPtrField< ::Serializer::Vector4f >*
Curve::mutable_keypoints() {
  return &keypoints_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Serializer

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Animation_2eproto__INCLUDED
