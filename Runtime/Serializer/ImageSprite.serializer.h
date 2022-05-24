// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ImageSprite.proto

#ifndef PROTOBUF_ImageSprite_2eproto__INCLUDED
#define PROTOBUF_ImageSprite_2eproto__INCLUDED

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
#include "Color.serializer.h"
// @@protoc_insertion_point(includes)

namespace Serializer {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ImageSprite_2eproto();
void protobuf_AssignDesc_ImageSprite_2eproto();
void protobuf_ShutdownFile_ImageSprite_2eproto();

class ImageSprite;
class ImageSprite9;

// ===================================================================

class ImageSprite : public ::google::protobuf::MessageLite {
 public:
  ImageSprite();
  virtual ~ImageSprite();
  
  ImageSprite(const ImageSprite& from);
  
  inline ImageSprite& operator=(const ImageSprite& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const ImageSprite& default_instance();
  
  void Swap(ImageSprite* other);
  
  // implements Message ----------------------------------------------
  
  ImageSprite* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const ImageSprite& from);
  void MergeFrom(const ImageSprite& from);
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
  
  // optional string image_path = 1;
  inline bool has_image_path() const;
  inline void clear_image_path();
  static const int kImagePathFieldNumber = 1;
  inline const ::std::string& image_path() const;
  inline void set_image_path(const ::std::string& value);
  inline void set_image_path(const char* value);
  inline void set_image_path(const char* value, size_t size);
  inline ::std::string* mutable_image_path();
  inline ::std::string* release_image_path();
  
  // optional string sprite_name = 2;
  inline bool has_sprite_name() const;
  inline void clear_sprite_name();
  static const int kSpriteNameFieldNumber = 2;
  inline const ::std::string& sprite_name() const;
  inline void set_sprite_name(const ::std::string& value);
  inline void set_sprite_name(const char* value);
  inline void set_sprite_name(const char* value, size_t size);
  inline ::std::string* mutable_sprite_name();
  inline ::std::string* release_sprite_name();
  
  // repeated float size = 3;
  inline int size_size() const;
  inline void clear_size();
  static const int kSizeFieldNumber = 3;
  inline float size(int index) const;
  inline void set_size(int index, float value);
  inline void add_size(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      size() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_size();
  
  // repeated float color = 4;
  inline int color_size() const;
  inline void clear_color();
  static const int kColorFieldNumber = 4;
  inline float color(int index) const;
  inline void set_color(int index, float value);
  inline void add_color(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      color() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_color();
  
  // repeated float dark_color = 5;
  inline int dark_color_size() const;
  inline void clear_dark_color();
  static const int kDarkColorFieldNumber = 5;
  inline float dark_color(int index) const;
  inline void set_dark_color(int index, float value);
  inline void add_dark_color(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      dark_color() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_dark_color();
  
  // optional int32 blend_func_src = 6;
  inline bool has_blend_func_src() const;
  inline void clear_blend_func_src();
  static const int kBlendFuncSrcFieldNumber = 6;
  inline ::google::protobuf::int32 blend_func_src() const;
  inline void set_blend_func_src(::google::protobuf::int32 value);
  
  // optional int32 blend_func_dst = 7;
  inline bool has_blend_func_dst() const;
  inline void clear_blend_func_dst();
  static const int kBlendFuncDstFieldNumber = 7;
  inline ::google::protobuf::int32 blend_func_dst() const;
  inline void set_blend_func_dst(::google::protobuf::int32 value);
  
  // optional string material = 8;
  inline bool has_material() const;
  inline void clear_material();
  static const int kMaterialFieldNumber = 8;
  inline const ::std::string& material() const;
  inline void set_material(const ::std::string& value);
  inline void set_material(const char* value);
  inline void set_material(const char* value, size_t size);
  inline ::std::string* mutable_material();
  inline ::std::string* release_material();
  
  // repeated float add_color = 9;
  inline int add_color_size() const;
  inline void clear_add_color();
  static const int kAddColorFieldNumber = 9;
  inline float add_color(int index) const;
  inline void set_add_color(int index, float value);
  inline void add_add_color(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      add_color() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_add_color();
  
  // @@protoc_insertion_point(class_scope:Serializer.ImageSprite)
 private:
  inline void set_has_image_path();
  inline void clear_has_image_path();
  inline void set_has_sprite_name();
  inline void clear_has_sprite_name();
  inline void set_has_blend_func_src();
  inline void clear_has_blend_func_src();
  inline void set_has_blend_func_dst();
  inline void clear_has_blend_func_dst();
  inline void set_has_material();
  inline void clear_has_material();
  
  ::std::string* image_path_;
  ::std::string* sprite_name_;
  ::google::protobuf::RepeatedField< float > size_;
  ::google::protobuf::RepeatedField< float > color_;
  ::google::protobuf::RepeatedField< float > dark_color_;
  ::google::protobuf::int32 blend_func_src_;
  ::google::protobuf::int32 blend_func_dst_;
  ::std::string* material_;
  ::google::protobuf::RepeatedField< float > add_color_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(9 + 31) / 32];
  
  friend void  protobuf_AddDesc_ImageSprite_2eproto();
  friend void protobuf_AssignDesc_ImageSprite_2eproto();
  friend void protobuf_ShutdownFile_ImageSprite_2eproto();
  
  void InitAsDefaultInstance();
  static ImageSprite* default_instance_;
};
// -------------------------------------------------------------------

class ImageSprite9 : public ::google::protobuf::MessageLite {
 public:
  ImageSprite9();
  virtual ~ImageSprite9();
  
  ImageSprite9(const ImageSprite9& from);
  
  inline ImageSprite9& operator=(const ImageSprite9& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const ImageSprite9& default_instance();
  
  void Swap(ImageSprite9* other);
  
  // implements Message ----------------------------------------------
  
  ImageSprite9* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const ImageSprite9& from);
  void MergeFrom(const ImageSprite9& from);
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
  
  // optional string image_path = 1;
  inline bool has_image_path() const;
  inline void clear_image_path();
  static const int kImagePathFieldNumber = 1;
  inline const ::std::string& image_path() const;
  inline void set_image_path(const ::std::string& value);
  inline void set_image_path(const char* value);
  inline void set_image_path(const char* value, size_t size);
  inline ::std::string* mutable_image_path();
  inline ::std::string* release_image_path();
  
  // optional string sprite_name = 2;
  inline bool has_sprite_name() const;
  inline void clear_sprite_name();
  static const int kSpriteNameFieldNumber = 2;
  inline const ::std::string& sprite_name() const;
  inline void set_sprite_name(const ::std::string& value);
  inline void set_sprite_name(const char* value);
  inline void set_sprite_name(const char* value, size_t size);
  inline ::std::string* mutable_sprite_name();
  inline ::std::string* release_sprite_name();
  
  // repeated float size = 3;
  inline int size_size() const;
  inline void clear_size();
  static const int kSizeFieldNumber = 3;
  inline float size(int index) const;
  inline void set_size(int index, float value);
  inline void add_size(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      size() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_size();
  
  // repeated float color = 4;
  inline int color_size() const;
  inline void clear_color();
  static const int kColorFieldNumber = 4;
  inline float color(int index) const;
  inline void set_color(int index, float value);
  inline void add_color(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      color() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_color();
  
  // repeated float dark_color = 5;
  inline int dark_color_size() const;
  inline void clear_dark_color();
  static const int kDarkColorFieldNumber = 5;
  inline float dark_color(int index) const;
  inline void set_dark_color(int index, float value);
  inline void add_dark_color(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      dark_color() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_dark_color();
  
  // optional int32 blend_func_src = 6;
  inline bool has_blend_func_src() const;
  inline void clear_blend_func_src();
  static const int kBlendFuncSrcFieldNumber = 6;
  inline ::google::protobuf::int32 blend_func_src() const;
  inline void set_blend_func_src(::google::protobuf::int32 value);
  
  // optional int32 blend_func_dst = 7;
  inline bool has_blend_func_dst() const;
  inline void clear_blend_func_dst();
  static const int kBlendFuncDstFieldNumber = 7;
  inline ::google::protobuf::int32 blend_func_dst() const;
  inline void set_blend_func_dst(::google::protobuf::int32 value);
  
  // optional string material = 8;
  inline bool has_material() const;
  inline void clear_material();
  static const int kMaterialFieldNumber = 8;
  inline const ::std::string& material() const;
  inline void set_material(const ::std::string& value);
  inline void set_material(const char* value);
  inline void set_material(const char* value, size_t size);
  inline ::std::string* mutable_material();
  inline ::std::string* release_material();
  
  // repeated int32 split = 9;
  inline int split_size() const;
  inline void clear_split();
  static const int kSplitFieldNumber = 9;
  inline ::google::protobuf::int32 split(int index) const;
  inline void set_split(int index, ::google::protobuf::int32 value);
  inline void add_split(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      split() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_split();
  
  // repeated float add_color = 10;
  inline int add_color_size() const;
  inline void clear_add_color();
  static const int kAddColorFieldNumber = 10;
  inline float add_color(int index) const;
  inline void set_add_color(int index, float value);
  inline void add_add_color(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      add_color() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_add_color();
  
  // @@protoc_insertion_point(class_scope:Serializer.ImageSprite9)
 private:
  inline void set_has_image_path();
  inline void clear_has_image_path();
  inline void set_has_sprite_name();
  inline void clear_has_sprite_name();
  inline void set_has_blend_func_src();
  inline void clear_has_blend_func_src();
  inline void set_has_blend_func_dst();
  inline void clear_has_blend_func_dst();
  inline void set_has_material();
  inline void clear_has_material();
  
  ::std::string* image_path_;
  ::std::string* sprite_name_;
  ::google::protobuf::RepeatedField< float > size_;
  ::google::protobuf::RepeatedField< float > color_;
  ::google::protobuf::RepeatedField< float > dark_color_;
  ::google::protobuf::int32 blend_func_src_;
  ::google::protobuf::int32 blend_func_dst_;
  ::std::string* material_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > split_;
  ::google::protobuf::RepeatedField< float > add_color_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(10 + 31) / 32];
  
  friend void  protobuf_AddDesc_ImageSprite_2eproto();
  friend void protobuf_AssignDesc_ImageSprite_2eproto();
  friend void protobuf_ShutdownFile_ImageSprite_2eproto();
  
  void InitAsDefaultInstance();
  static ImageSprite9* default_instance_;
};
// ===================================================================


// ===================================================================

// ImageSprite

// optional string image_path = 1;
inline bool ImageSprite::has_image_path() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ImageSprite::set_has_image_path() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ImageSprite::clear_has_image_path() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ImageSprite::clear_image_path() {
  if (image_path_ != &::google::protobuf::internal::kEmptyString) {
    image_path_->clear();
  }
  clear_has_image_path();
}
inline const ::std::string& ImageSprite::image_path() const {
  return *image_path_;
}
inline void ImageSprite::set_image_path(const ::std::string& value) {
  set_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    image_path_ = new ::std::string;
  }
  image_path_->assign(value);
}
inline void ImageSprite::set_image_path(const char* value) {
  set_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    image_path_ = new ::std::string;
  }
  image_path_->assign(value);
}
inline void ImageSprite::set_image_path(const char* value, size_t size) {
  set_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    image_path_ = new ::std::string;
  }
  image_path_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageSprite::mutable_image_path() {
  set_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    image_path_ = new ::std::string;
  }
  return image_path_;
}
inline ::std::string* ImageSprite::release_image_path() {
  clear_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = image_path_;
    image_path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string sprite_name = 2;
inline bool ImageSprite::has_sprite_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ImageSprite::set_has_sprite_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ImageSprite::clear_has_sprite_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ImageSprite::clear_sprite_name() {
  if (sprite_name_ != &::google::protobuf::internal::kEmptyString) {
    sprite_name_->clear();
  }
  clear_has_sprite_name();
}
inline const ::std::string& ImageSprite::sprite_name() const {
  return *sprite_name_;
}
inline void ImageSprite::set_sprite_name(const ::std::string& value) {
  set_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    sprite_name_ = new ::std::string;
  }
  sprite_name_->assign(value);
}
inline void ImageSprite::set_sprite_name(const char* value) {
  set_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    sprite_name_ = new ::std::string;
  }
  sprite_name_->assign(value);
}
inline void ImageSprite::set_sprite_name(const char* value, size_t size) {
  set_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    sprite_name_ = new ::std::string;
  }
  sprite_name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageSprite::mutable_sprite_name() {
  set_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    sprite_name_ = new ::std::string;
  }
  return sprite_name_;
}
inline ::std::string* ImageSprite::release_sprite_name() {
  clear_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = sprite_name_;
    sprite_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated float size = 3;
inline int ImageSprite::size_size() const {
  return size_.size();
}
inline void ImageSprite::clear_size() {
  size_.Clear();
}
inline float ImageSprite::size(int index) const {
  return size_.Get(index);
}
inline void ImageSprite::set_size(int index, float value) {
  size_.Set(index, value);
}
inline void ImageSprite::add_size(float value) {
  size_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ImageSprite::size() const {
  return size_;
}
inline ::google::protobuf::RepeatedField< float >*
ImageSprite::mutable_size() {
  return &size_;
}

// repeated float color = 4;
inline int ImageSprite::color_size() const {
  return color_.size();
}
inline void ImageSprite::clear_color() {
  color_.Clear();
}
inline float ImageSprite::color(int index) const {
  return color_.Get(index);
}
inline void ImageSprite::set_color(int index, float value) {
  color_.Set(index, value);
}
inline void ImageSprite::add_color(float value) {
  color_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ImageSprite::color() const {
  return color_;
}
inline ::google::protobuf::RepeatedField< float >*
ImageSprite::mutable_color() {
  return &color_;
}

// repeated float dark_color = 5;
inline int ImageSprite::dark_color_size() const {
  return dark_color_.size();
}
inline void ImageSprite::clear_dark_color() {
  dark_color_.Clear();
}
inline float ImageSprite::dark_color(int index) const {
  return dark_color_.Get(index);
}
inline void ImageSprite::set_dark_color(int index, float value) {
  dark_color_.Set(index, value);
}
inline void ImageSprite::add_dark_color(float value) {
  dark_color_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ImageSprite::dark_color() const {
  return dark_color_;
}
inline ::google::protobuf::RepeatedField< float >*
ImageSprite::mutable_dark_color() {
  return &dark_color_;
}

// optional int32 blend_func_src = 6;
inline bool ImageSprite::has_blend_func_src() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ImageSprite::set_has_blend_func_src() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ImageSprite::clear_has_blend_func_src() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ImageSprite::clear_blend_func_src() {
  blend_func_src_ = 0;
  clear_has_blend_func_src();
}
inline ::google::protobuf::int32 ImageSprite::blend_func_src() const {
  return blend_func_src_;
}
inline void ImageSprite::set_blend_func_src(::google::protobuf::int32 value) {
  set_has_blend_func_src();
  blend_func_src_ = value;
}

// optional int32 blend_func_dst = 7;
inline bool ImageSprite::has_blend_func_dst() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void ImageSprite::set_has_blend_func_dst() {
  _has_bits_[0] |= 0x00000040u;
}
inline void ImageSprite::clear_has_blend_func_dst() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void ImageSprite::clear_blend_func_dst() {
  blend_func_dst_ = 0;
  clear_has_blend_func_dst();
}
inline ::google::protobuf::int32 ImageSprite::blend_func_dst() const {
  return blend_func_dst_;
}
inline void ImageSprite::set_blend_func_dst(::google::protobuf::int32 value) {
  set_has_blend_func_dst();
  blend_func_dst_ = value;
}

// optional string material = 8;
inline bool ImageSprite::has_material() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void ImageSprite::set_has_material() {
  _has_bits_[0] |= 0x00000080u;
}
inline void ImageSprite::clear_has_material() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void ImageSprite::clear_material() {
  if (material_ != &::google::protobuf::internal::kEmptyString) {
    material_->clear();
  }
  clear_has_material();
}
inline const ::std::string& ImageSprite::material() const {
  return *material_;
}
inline void ImageSprite::set_material(const ::std::string& value) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(value);
}
inline void ImageSprite::set_material(const char* value) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(value);
}
inline void ImageSprite::set_material(const char* value, size_t size) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageSprite::mutable_material() {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  return material_;
}
inline ::std::string* ImageSprite::release_material() {
  clear_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = material_;
    material_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated float add_color = 9;
inline int ImageSprite::add_color_size() const {
  return add_color_.size();
}
inline void ImageSprite::clear_add_color() {
  add_color_.Clear();
}
inline float ImageSprite::add_color(int index) const {
  return add_color_.Get(index);
}
inline void ImageSprite::set_add_color(int index, float value) {
  add_color_.Set(index, value);
}
inline void ImageSprite::add_add_color(float value) {
  add_color_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ImageSprite::add_color() const {
  return add_color_;
}
inline ::google::protobuf::RepeatedField< float >*
ImageSprite::mutable_add_color() {
  return &add_color_;
}

// -------------------------------------------------------------------

// ImageSprite9

// optional string image_path = 1;
inline bool ImageSprite9::has_image_path() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ImageSprite9::set_has_image_path() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ImageSprite9::clear_has_image_path() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ImageSprite9::clear_image_path() {
  if (image_path_ != &::google::protobuf::internal::kEmptyString) {
    image_path_->clear();
  }
  clear_has_image_path();
}
inline const ::std::string& ImageSprite9::image_path() const {
  return *image_path_;
}
inline void ImageSprite9::set_image_path(const ::std::string& value) {
  set_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    image_path_ = new ::std::string;
  }
  image_path_->assign(value);
}
inline void ImageSprite9::set_image_path(const char* value) {
  set_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    image_path_ = new ::std::string;
  }
  image_path_->assign(value);
}
inline void ImageSprite9::set_image_path(const char* value, size_t size) {
  set_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    image_path_ = new ::std::string;
  }
  image_path_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageSprite9::mutable_image_path() {
  set_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    image_path_ = new ::std::string;
  }
  return image_path_;
}
inline ::std::string* ImageSprite9::release_image_path() {
  clear_has_image_path();
  if (image_path_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = image_path_;
    image_path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string sprite_name = 2;
inline bool ImageSprite9::has_sprite_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ImageSprite9::set_has_sprite_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ImageSprite9::clear_has_sprite_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ImageSprite9::clear_sprite_name() {
  if (sprite_name_ != &::google::protobuf::internal::kEmptyString) {
    sprite_name_->clear();
  }
  clear_has_sprite_name();
}
inline const ::std::string& ImageSprite9::sprite_name() const {
  return *sprite_name_;
}
inline void ImageSprite9::set_sprite_name(const ::std::string& value) {
  set_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    sprite_name_ = new ::std::string;
  }
  sprite_name_->assign(value);
}
inline void ImageSprite9::set_sprite_name(const char* value) {
  set_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    sprite_name_ = new ::std::string;
  }
  sprite_name_->assign(value);
}
inline void ImageSprite9::set_sprite_name(const char* value, size_t size) {
  set_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    sprite_name_ = new ::std::string;
  }
  sprite_name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageSprite9::mutable_sprite_name() {
  set_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    sprite_name_ = new ::std::string;
  }
  return sprite_name_;
}
inline ::std::string* ImageSprite9::release_sprite_name() {
  clear_has_sprite_name();
  if (sprite_name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = sprite_name_;
    sprite_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated float size = 3;
inline int ImageSprite9::size_size() const {
  return size_.size();
}
inline void ImageSprite9::clear_size() {
  size_.Clear();
}
inline float ImageSprite9::size(int index) const {
  return size_.Get(index);
}
inline void ImageSprite9::set_size(int index, float value) {
  size_.Set(index, value);
}
inline void ImageSprite9::add_size(float value) {
  size_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ImageSprite9::size() const {
  return size_;
}
inline ::google::protobuf::RepeatedField< float >*
ImageSprite9::mutable_size() {
  return &size_;
}

// repeated float color = 4;
inline int ImageSprite9::color_size() const {
  return color_.size();
}
inline void ImageSprite9::clear_color() {
  color_.Clear();
}
inline float ImageSprite9::color(int index) const {
  return color_.Get(index);
}
inline void ImageSprite9::set_color(int index, float value) {
  color_.Set(index, value);
}
inline void ImageSprite9::add_color(float value) {
  color_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ImageSprite9::color() const {
  return color_;
}
inline ::google::protobuf::RepeatedField< float >*
ImageSprite9::mutable_color() {
  return &color_;
}

// repeated float dark_color = 5;
inline int ImageSprite9::dark_color_size() const {
  return dark_color_.size();
}
inline void ImageSprite9::clear_dark_color() {
  dark_color_.Clear();
}
inline float ImageSprite9::dark_color(int index) const {
  return dark_color_.Get(index);
}
inline void ImageSprite9::set_dark_color(int index, float value) {
  dark_color_.Set(index, value);
}
inline void ImageSprite9::add_dark_color(float value) {
  dark_color_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ImageSprite9::dark_color() const {
  return dark_color_;
}
inline ::google::protobuf::RepeatedField< float >*
ImageSprite9::mutable_dark_color() {
  return &dark_color_;
}

// optional int32 blend_func_src = 6;
inline bool ImageSprite9::has_blend_func_src() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ImageSprite9::set_has_blend_func_src() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ImageSprite9::clear_has_blend_func_src() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ImageSprite9::clear_blend_func_src() {
  blend_func_src_ = 0;
  clear_has_blend_func_src();
}
inline ::google::protobuf::int32 ImageSprite9::blend_func_src() const {
  return blend_func_src_;
}
inline void ImageSprite9::set_blend_func_src(::google::protobuf::int32 value) {
  set_has_blend_func_src();
  blend_func_src_ = value;
}

// optional int32 blend_func_dst = 7;
inline bool ImageSprite9::has_blend_func_dst() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void ImageSprite9::set_has_blend_func_dst() {
  _has_bits_[0] |= 0x00000040u;
}
inline void ImageSprite9::clear_has_blend_func_dst() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void ImageSprite9::clear_blend_func_dst() {
  blend_func_dst_ = 0;
  clear_has_blend_func_dst();
}
inline ::google::protobuf::int32 ImageSprite9::blend_func_dst() const {
  return blend_func_dst_;
}
inline void ImageSprite9::set_blend_func_dst(::google::protobuf::int32 value) {
  set_has_blend_func_dst();
  blend_func_dst_ = value;
}

// optional string material = 8;
inline bool ImageSprite9::has_material() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void ImageSprite9::set_has_material() {
  _has_bits_[0] |= 0x00000080u;
}
inline void ImageSprite9::clear_has_material() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void ImageSprite9::clear_material() {
  if (material_ != &::google::protobuf::internal::kEmptyString) {
    material_->clear();
  }
  clear_has_material();
}
inline const ::std::string& ImageSprite9::material() const {
  return *material_;
}
inline void ImageSprite9::set_material(const ::std::string& value) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(value);
}
inline void ImageSprite9::set_material(const char* value) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(value);
}
inline void ImageSprite9::set_material(const char* value, size_t size) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageSprite9::mutable_material() {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  return material_;
}
inline ::std::string* ImageSprite9::release_material() {
  clear_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = material_;
    material_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated int32 split = 9;
inline int ImageSprite9::split_size() const {
  return split_.size();
}
inline void ImageSprite9::clear_split() {
  split_.Clear();
}
inline ::google::protobuf::int32 ImageSprite9::split(int index) const {
  return split_.Get(index);
}
inline void ImageSprite9::set_split(int index, ::google::protobuf::int32 value) {
  split_.Set(index, value);
}
inline void ImageSprite9::add_split(::google::protobuf::int32 value) {
  split_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
ImageSprite9::split() const {
  return split_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
ImageSprite9::mutable_split() {
  return &split_;
}

// repeated float add_color = 10;
inline int ImageSprite9::add_color_size() const {
  return add_color_.size();
}
inline void ImageSprite9::clear_add_color() {
  add_color_.Clear();
}
inline float ImageSprite9::add_color(int index) const {
  return add_color_.Get(index);
}
inline void ImageSprite9::set_add_color(int index, float value) {
  add_color_.Set(index, value);
}
inline void ImageSprite9::add_add_color(float value) {
  add_color_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ImageSprite9::add_color() const {
  return add_color_;
}
inline ::google::protobuf::RepeatedField< float >*
ImageSprite9::mutable_add_color() {
  return &add_color_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Serializer

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ImageSprite_2eproto__INCLUDED
