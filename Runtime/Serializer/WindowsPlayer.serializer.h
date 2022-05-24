// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: WindowsPlayer.proto

#ifndef PROTOBUF_WindowsPlayer_2eproto__INCLUDED
#define PROTOBUF_WindowsPlayer_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace Serializer {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_WindowsPlayer_2eproto();
void protobuf_AssignDesc_WindowsPlayer_2eproto();
void protobuf_ShutdownFile_WindowsPlayer_2eproto();

class WinPlayerSize;
class WinPlayerSettings;

// ===================================================================

class WinPlayerSize : public ::google::protobuf::MessageLite {
 public:
  WinPlayerSize();
  virtual ~WinPlayerSize();
  
  WinPlayerSize(const WinPlayerSize& from);
  
  inline WinPlayerSize& operator=(const WinPlayerSize& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const WinPlayerSize& default_instance();
  
  void Swap(WinPlayerSize* other);
  
  // implements Message ----------------------------------------------
  
  WinPlayerSize* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const WinPlayerSize& from);
  void MergeFrom(const WinPlayerSize& from);
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
  
  // optional int32 width = 1;
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 1;
  inline ::google::protobuf::int32 width() const;
  inline void set_width(::google::protobuf::int32 value);
  
  // optional int32 height = 2;
  inline bool has_height() const;
  inline void clear_height();
  static const int kHeightFieldNumber = 2;
  inline ::google::protobuf::int32 height() const;
  inline void set_height(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:Serializer.WinPlayerSize)
 private:
  inline void set_has_width();
  inline void clear_has_width();
  inline void set_has_height();
  inline void clear_has_height();
  
  ::google::protobuf::int32 width_;
  ::google::protobuf::int32 height_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_WindowsPlayer_2eproto();
  friend void protobuf_AssignDesc_WindowsPlayer_2eproto();
  friend void protobuf_ShutdownFile_WindowsPlayer_2eproto();
  
  void InitAsDefaultInstance();
  static WinPlayerSize* default_instance_;
};
// -------------------------------------------------------------------

class WinPlayerSettings : public ::google::protobuf::MessageLite {
 public:
  WinPlayerSettings();
  virtual ~WinPlayerSettings();
  
  WinPlayerSettings(const WinPlayerSettings& from);
  
  inline WinPlayerSettings& operator=(const WinPlayerSettings& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const WinPlayerSettings& default_instance();
  
  void Swap(WinPlayerSettings* other);
  
  // implements Message ----------------------------------------------
  
  WinPlayerSettings* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const WinPlayerSettings& from);
  void MergeFrom(const WinPlayerSettings& from);
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
  
  // repeated .Serializer.WinPlayerSize predefined_resolution = 1;
  inline int predefined_resolution_size() const;
  inline void clear_predefined_resolution();
  static const int kPredefinedResolutionFieldNumber = 1;
  inline const ::Serializer::WinPlayerSize& predefined_resolution(int index) const;
  inline ::Serializer::WinPlayerSize* mutable_predefined_resolution(int index);
  inline ::Serializer::WinPlayerSize* add_predefined_resolution();
  inline const ::google::protobuf::RepeatedPtrField< ::Serializer::WinPlayerSize >&
      predefined_resolution() const;
  inline ::google::protobuf::RepeatedPtrField< ::Serializer::WinPlayerSize >*
      mutable_predefined_resolution();
  
  // @@protoc_insertion_point(class_scope:Serializer.WinPlayerSettings)
 private:
  
  ::google::protobuf::RepeatedPtrField< ::Serializer::WinPlayerSize > predefined_resolution_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_WindowsPlayer_2eproto();
  friend void protobuf_AssignDesc_WindowsPlayer_2eproto();
  friend void protobuf_ShutdownFile_WindowsPlayer_2eproto();
  
  void InitAsDefaultInstance();
  static WinPlayerSettings* default_instance_;
};
// ===================================================================


// ===================================================================

// WinPlayerSize

// optional int32 width = 1;
inline bool WinPlayerSize::has_width() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void WinPlayerSize::set_has_width() {
  _has_bits_[0] |= 0x00000001u;
}
inline void WinPlayerSize::clear_has_width() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void WinPlayerSize::clear_width() {
  width_ = 0;
  clear_has_width();
}
inline ::google::protobuf::int32 WinPlayerSize::width() const {
  return width_;
}
inline void WinPlayerSize::set_width(::google::protobuf::int32 value) {
  set_has_width();
  width_ = value;
}

// optional int32 height = 2;
inline bool WinPlayerSize::has_height() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void WinPlayerSize::set_has_height() {
  _has_bits_[0] |= 0x00000002u;
}
inline void WinPlayerSize::clear_has_height() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void WinPlayerSize::clear_height() {
  height_ = 0;
  clear_has_height();
}
inline ::google::protobuf::int32 WinPlayerSize::height() const {
  return height_;
}
inline void WinPlayerSize::set_height(::google::protobuf::int32 value) {
  set_has_height();
  height_ = value;
}

// -------------------------------------------------------------------

// WinPlayerSettings

// repeated .Serializer.WinPlayerSize predefined_resolution = 1;
inline int WinPlayerSettings::predefined_resolution_size() const {
  return predefined_resolution_.size();
}
inline void WinPlayerSettings::clear_predefined_resolution() {
  predefined_resolution_.Clear();
}
inline const ::Serializer::WinPlayerSize& WinPlayerSettings::predefined_resolution(int index) const {
  return predefined_resolution_.Get(index);
}
inline ::Serializer::WinPlayerSize* WinPlayerSettings::mutable_predefined_resolution(int index) {
  return predefined_resolution_.Mutable(index);
}
inline ::Serializer::WinPlayerSize* WinPlayerSettings::add_predefined_resolution() {
  return predefined_resolution_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Serializer::WinPlayerSize >&
WinPlayerSettings::predefined_resolution() const {
  return predefined_resolution_;
}
inline ::google::protobuf::RepeatedPtrField< ::Serializer::WinPlayerSize >*
WinPlayerSettings::mutable_predefined_resolution() {
  return &predefined_resolution_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Serializer

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_WindowsPlayer_2eproto__INCLUDED
