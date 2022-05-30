// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GameObject.proto

#ifndef PROTOBUF_GameObject_2eproto__INCLUDED
#define PROTOBUF_GameObject_2eproto__INCLUDED

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
#include "ImageSprite.serializer.h"
// @@protoc_insertion_point(includes)

namespace Serializer {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_GameObject_2eproto();
void protobuf_AssignDesc_GameObject_2eproto();
void protobuf_ShutdownFile_GameObject_2eproto();

class Transform;
class GameObject;

// ===================================================================

class Transform : public ::google::protobuf::MessageLite {
 public:
  Transform();
  virtual ~Transform();
  
  Transform(const Transform& from);
  
  inline Transform& operator=(const Transform& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const Transform& default_instance();
  
  void Swap(Transform* other);
  
  // implements Message ----------------------------------------------
  
  Transform* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Transform& from);
  void MergeFrom(const Transform& from);
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
  
  // repeated float position = 1;
  inline int position_size() const;
  inline void clear_position();
  static const int kPositionFieldNumber = 1;
  inline float position(int index) const;
  inline void set_position(int index, float value);
  inline void add_position(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      position() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_position();
  
  // repeated float rotation = 2;
  inline int rotation_size() const;
  inline void clear_rotation();
  static const int kRotationFieldNumber = 2;
  inline float rotation(int index) const;
  inline void set_rotation(int index, float value);
  inline void add_rotation(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      rotation() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_rotation();
  
  // repeated float scale = 3;
  inline int scale_size() const;
  inline void clear_scale();
  static const int kScaleFieldNumber = 3;
  inline float scale(int index) const;
  inline void set_scale(int index, float value);
  inline void add_scale(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      scale() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_scale();
  
  // repeated float shear = 4;
  inline int shear_size() const;
  inline void clear_shear();
  static const int kShearFieldNumber = 4;
  inline float shear(int index) const;
  inline void set_shear(int index, float value);
  inline void add_shear(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      shear() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_shear();
  
  // optional int32 type = 5;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 5;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:Serializer.Transform)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  
  ::google::protobuf::RepeatedField< float > position_;
  ::google::protobuf::RepeatedField< float > rotation_;
  ::google::protobuf::RepeatedField< float > scale_;
  ::google::protobuf::RepeatedField< float > shear_;
  ::google::protobuf::int32 type_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];
  
  friend void  protobuf_AddDesc_GameObject_2eproto();
  friend void protobuf_AssignDesc_GameObject_2eproto();
  friend void protobuf_ShutdownFile_GameObject_2eproto();
  
  void InitAsDefaultInstance();
  static Transform* default_instance_;
};
// -------------------------------------------------------------------

class GameObject : public ::google::protobuf::MessageLite {
 public:
  GameObject();
  virtual ~GameObject();
  
  GameObject(const GameObject& from);
  
  inline GameObject& operator=(const GameObject& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const GameObject& default_instance();
  
  void Swap(GameObject* other);
  
  // implements Message ----------------------------------------------
  
  GameObject* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const GameObject& from);
  void MergeFrom(const GameObject& from);
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
  
  // optional string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  
  // optional uint32 layer = 2;
  inline bool has_layer() const;
  inline void clear_layer();
  static const int kLayerFieldNumber = 2;
  inline ::google::protobuf::uint32 layer() const;
  inline void set_layer(::google::protobuf::uint32 value);
  
  // optional bool enable = 3;
  inline bool has_enable() const;
  inline void clear_enable();
  static const int kEnableFieldNumber = 3;
  inline bool enable() const;
  inline void set_enable(bool value);
  
  // optional .Serializer.Transform transform = 4;
  inline bool has_transform() const;
  inline void clear_transform();
  static const int kTransformFieldNumber = 4;
  inline const ::Serializer::Transform& transform() const;
  inline ::Serializer::Transform* mutable_transform();
  inline ::Serializer::Transform* release_transform();
  
  // optional .Serializer.GameObject child = 5;
  inline bool has_child() const;
  inline void clear_child();
  static const int kChildFieldNumber = 5;
  inline const ::Serializer::GameObject& child() const;
  inline ::Serializer::GameObject* mutable_child();
  inline ::Serializer::GameObject* release_child();
  
  // optional .Serializer.GameObject left_sibling = 6;
  inline bool has_left_sibling() const;
  inline void clear_left_sibling();
  static const int kLeftSiblingFieldNumber = 6;
  inline const ::Serializer::GameObject& left_sibling() const;
  inline ::Serializer::GameObject* mutable_left_sibling();
  inline ::Serializer::GameObject* release_left_sibling();
  
  // optional .Serializer.GameObject right_sibling = 7;
  inline bool has_right_sibling() const;
  inline void clear_right_sibling();
  static const int kRightSiblingFieldNumber = 7;
  inline const ::Serializer::GameObject& right_sibling() const;
  inline ::Serializer::GameObject* mutable_right_sibling();
  inline ::Serializer::GameObject* release_right_sibling();
  
  // optional bytes extra_data = 8;
  inline bool has_extra_data() const;
  inline void clear_extra_data();
  static const int kExtraDataFieldNumber = 8;
  inline const ::std::string& extra_data() const;
  inline void set_extra_data(const ::std::string& value);
  inline void set_extra_data(const char* value);
  inline void set_extra_data(const void* value, size_t size);
  inline ::std::string* mutable_extra_data();
  inline ::std::string* release_extra_data();
  
  // repeated string render_order = 9;
  inline int render_order_size() const;
  inline void clear_render_order();
  static const int kRenderOrderFieldNumber = 9;
  inline const ::std::string& render_order(int index) const;
  inline ::std::string* mutable_render_order(int index);
  inline void set_render_order(int index, const ::std::string& value);
  inline void set_render_order(int index, const char* value);
  inline void set_render_order(int index, const char* value, size_t size);
  inline ::std::string* add_render_order();
  inline void add_render_order(const ::std::string& value);
  inline void add_render_order(const char* value);
  inline void add_render_order(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& render_order() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_render_order();
  
  // optional .Serializer.ImageSprite imageSprite = 10;
  inline bool has_imagesprite() const;
  inline void clear_imagesprite();
  static const int kImageSpriteFieldNumber = 10;
  inline const ::Serializer::ImageSprite& imagesprite() const;
  inline ::Serializer::ImageSprite* mutable_imagesprite();
  inline ::Serializer::ImageSprite* release_imagesprite();
  
  // optional .Serializer.ImageSprite9 imagesprite9 = 11;
  inline bool has_imagesprite9() const;
  inline void clear_imagesprite9();
  static const int kImagesprite9FieldNumber = 11;
  inline const ::Serializer::ImageSprite9& imagesprite9() const;
  inline ::Serializer::ImageSprite9* mutable_imagesprite9();
  inline ::Serializer::ImageSprite9* release_imagesprite9();
  
  // @@protoc_insertion_point(class_scope:Serializer.GameObject)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_layer();
  inline void clear_has_layer();
  inline void set_has_enable();
  inline void clear_has_enable();
  inline void set_has_transform();
  inline void clear_has_transform();
  inline void set_has_child();
  inline void clear_has_child();
  inline void set_has_left_sibling();
  inline void clear_has_left_sibling();
  inline void set_has_right_sibling();
  inline void clear_has_right_sibling();
  inline void set_has_extra_data();
  inline void clear_has_extra_data();
  inline void set_has_imagesprite();
  inline void clear_has_imagesprite();
  inline void set_has_imagesprite9();
  inline void clear_has_imagesprite9();
  
  ::std::string* name_;
  ::google::protobuf::uint32 layer_;
  bool enable_;
  ::Serializer::Transform* transform_;
  ::Serializer::GameObject* child_;
  ::Serializer::GameObject* left_sibling_;
  ::Serializer::GameObject* right_sibling_;
  ::std::string* extra_data_;
  ::google::protobuf::RepeatedPtrField< ::std::string> render_order_;
  ::Serializer::ImageSprite* imagesprite_;
  ::Serializer::ImageSprite9* imagesprite9_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(11 + 31) / 32];
  
  friend void  protobuf_AddDesc_GameObject_2eproto();
  friend void protobuf_AssignDesc_GameObject_2eproto();
  friend void protobuf_ShutdownFile_GameObject_2eproto();
  
  void InitAsDefaultInstance();
  static GameObject* default_instance_;
};
// ===================================================================


// ===================================================================

// Transform

// repeated float position = 1;
inline int Transform::position_size() const {
  return position_.size();
}
inline void Transform::clear_position() {
  position_.Clear();
}
inline float Transform::position(int index) const {
  return position_.Get(index);
}
inline void Transform::set_position(int index, float value) {
  position_.Set(index, value);
}
inline void Transform::add_position(float value) {
  position_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
Transform::position() const {
  return position_;
}
inline ::google::protobuf::RepeatedField< float >*
Transform::mutable_position() {
  return &position_;
}

// repeated float rotation = 2;
inline int Transform::rotation_size() const {
  return rotation_.size();
}
inline void Transform::clear_rotation() {
  rotation_.Clear();
}
inline float Transform::rotation(int index) const {
  return rotation_.Get(index);
}
inline void Transform::set_rotation(int index, float value) {
  rotation_.Set(index, value);
}
inline void Transform::add_rotation(float value) {
  rotation_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
Transform::rotation() const {
  return rotation_;
}
inline ::google::protobuf::RepeatedField< float >*
Transform::mutable_rotation() {
  return &rotation_;
}

// repeated float scale = 3;
inline int Transform::scale_size() const {
  return scale_.size();
}
inline void Transform::clear_scale() {
  scale_.Clear();
}
inline float Transform::scale(int index) const {
  return scale_.Get(index);
}
inline void Transform::set_scale(int index, float value) {
  scale_.Set(index, value);
}
inline void Transform::add_scale(float value) {
  scale_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
Transform::scale() const {
  return scale_;
}
inline ::google::protobuf::RepeatedField< float >*
Transform::mutable_scale() {
  return &scale_;
}

// repeated float shear = 4;
inline int Transform::shear_size() const {
  return shear_.size();
}
inline void Transform::clear_shear() {
  shear_.Clear();
}
inline float Transform::shear(int index) const {
  return shear_.Get(index);
}
inline void Transform::set_shear(int index, float value) {
  shear_.Set(index, value);
}
inline void Transform::add_shear(float value) {
  shear_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
Transform::shear() const {
  return shear_;
}
inline ::google::protobuf::RepeatedField< float >*
Transform::mutable_shear() {
  return &shear_;
}

// optional int32 type = 5;
inline bool Transform::has_type() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Transform::set_has_type() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Transform::clear_has_type() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Transform::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 Transform::type() const {
  return type_;
}
inline void Transform::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// -------------------------------------------------------------------

// GameObject

// optional string name = 1;
inline bool GameObject::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GameObject::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GameObject::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GameObject::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& GameObject::name() const {
  return *name_;
}
inline void GameObject::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void GameObject::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void GameObject::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* GameObject::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* GameObject::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional uint32 layer = 2;
inline bool GameObject::has_layer() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GameObject::set_has_layer() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GameObject::clear_has_layer() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GameObject::clear_layer() {
  layer_ = 0u;
  clear_has_layer();
}
inline ::google::protobuf::uint32 GameObject::layer() const {
  return layer_;
}
inline void GameObject::set_layer(::google::protobuf::uint32 value) {
  set_has_layer();
  layer_ = value;
}

// optional bool enable = 3;
inline bool GameObject::has_enable() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void GameObject::set_has_enable() {
  _has_bits_[0] |= 0x00000004u;
}
inline void GameObject::clear_has_enable() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void GameObject::clear_enable() {
  enable_ = false;
  clear_has_enable();
}
inline bool GameObject::enable() const {
  return enable_;
}
inline void GameObject::set_enable(bool value) {
  set_has_enable();
  enable_ = value;
}

// optional .Serializer.Transform transform = 4;
inline bool GameObject::has_transform() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void GameObject::set_has_transform() {
  _has_bits_[0] |= 0x00000008u;
}
inline void GameObject::clear_has_transform() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void GameObject::clear_transform() {
  if (transform_ != NULL) transform_->::Serializer::Transform::Clear();
  clear_has_transform();
}
inline const ::Serializer::Transform& GameObject::transform() const {
  return transform_ != NULL ? *transform_ : *default_instance_->transform_;
}
inline ::Serializer::Transform* GameObject::mutable_transform() {
  set_has_transform();
  if (transform_ == NULL) transform_ = new ::Serializer::Transform;
  return transform_;
}
inline ::Serializer::Transform* GameObject::release_transform() {
  clear_has_transform();
  ::Serializer::Transform* temp = transform_;
  transform_ = NULL;
  return temp;
}

// optional .Serializer.GameObject child = 5;
inline bool GameObject::has_child() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void GameObject::set_has_child() {
  _has_bits_[0] |= 0x00000010u;
}
inline void GameObject::clear_has_child() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void GameObject::clear_child() {
  if (child_ != NULL) child_->::Serializer::GameObject::Clear();
  clear_has_child();
}
inline const ::Serializer::GameObject& GameObject::child() const {
  return child_ != NULL ? *child_ : *default_instance_->child_;
}
inline ::Serializer::GameObject* GameObject::mutable_child() {
  set_has_child();
  if (child_ == NULL) child_ = new ::Serializer::GameObject;
  return child_;
}
inline ::Serializer::GameObject* GameObject::release_child() {
  clear_has_child();
  ::Serializer::GameObject* temp = child_;
  child_ = NULL;
  return temp;
}

// optional .Serializer.GameObject left_sibling = 6;
inline bool GameObject::has_left_sibling() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void GameObject::set_has_left_sibling() {
  _has_bits_[0] |= 0x00000020u;
}
inline void GameObject::clear_has_left_sibling() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void GameObject::clear_left_sibling() {
  if (left_sibling_ != NULL) left_sibling_->::Serializer::GameObject::Clear();
  clear_has_left_sibling();
}
inline const ::Serializer::GameObject& GameObject::left_sibling() const {
  return left_sibling_ != NULL ? *left_sibling_ : *default_instance_->left_sibling_;
}
inline ::Serializer::GameObject* GameObject::mutable_left_sibling() {
  set_has_left_sibling();
  if (left_sibling_ == NULL) left_sibling_ = new ::Serializer::GameObject;
  return left_sibling_;
}
inline ::Serializer::GameObject* GameObject::release_left_sibling() {
  clear_has_left_sibling();
  ::Serializer::GameObject* temp = left_sibling_;
  left_sibling_ = NULL;
  return temp;
}

// optional .Serializer.GameObject right_sibling = 7;
inline bool GameObject::has_right_sibling() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void GameObject::set_has_right_sibling() {
  _has_bits_[0] |= 0x00000040u;
}
inline void GameObject::clear_has_right_sibling() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void GameObject::clear_right_sibling() {
  if (right_sibling_ != NULL) right_sibling_->::Serializer::GameObject::Clear();
  clear_has_right_sibling();
}
inline const ::Serializer::GameObject& GameObject::right_sibling() const {
  return right_sibling_ != NULL ? *right_sibling_ : *default_instance_->right_sibling_;
}
inline ::Serializer::GameObject* GameObject::mutable_right_sibling() {
  set_has_right_sibling();
  if (right_sibling_ == NULL) right_sibling_ = new ::Serializer::GameObject;
  return right_sibling_;
}
inline ::Serializer::GameObject* GameObject::release_right_sibling() {
  clear_has_right_sibling();
  ::Serializer::GameObject* temp = right_sibling_;
  right_sibling_ = NULL;
  return temp;
}

// optional bytes extra_data = 8;
inline bool GameObject::has_extra_data() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void GameObject::set_has_extra_data() {
  _has_bits_[0] |= 0x00000080u;
}
inline void GameObject::clear_has_extra_data() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void GameObject::clear_extra_data() {
  if (extra_data_ != &::google::protobuf::internal::kEmptyString) {
    extra_data_->clear();
  }
  clear_has_extra_data();
}
inline const ::std::string& GameObject::extra_data() const {
  return *extra_data_;
}
inline void GameObject::set_extra_data(const ::std::string& value) {
  set_has_extra_data();
  if (extra_data_ == &::google::protobuf::internal::kEmptyString) {
    extra_data_ = new ::std::string;
  }
  extra_data_->assign(value);
}
inline void GameObject::set_extra_data(const char* value) {
  set_has_extra_data();
  if (extra_data_ == &::google::protobuf::internal::kEmptyString) {
    extra_data_ = new ::std::string;
  }
  extra_data_->assign(value);
}
inline void GameObject::set_extra_data(const void* value, size_t size) {
  set_has_extra_data();
  if (extra_data_ == &::google::protobuf::internal::kEmptyString) {
    extra_data_ = new ::std::string;
  }
  extra_data_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* GameObject::mutable_extra_data() {
  set_has_extra_data();
  if (extra_data_ == &::google::protobuf::internal::kEmptyString) {
    extra_data_ = new ::std::string;
  }
  return extra_data_;
}
inline ::std::string* GameObject::release_extra_data() {
  clear_has_extra_data();
  if (extra_data_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = extra_data_;
    extra_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated string render_order = 9;
inline int GameObject::render_order_size() const {
  return render_order_.size();
}
inline void GameObject::clear_render_order() {
  render_order_.Clear();
}
inline const ::std::string& GameObject::render_order(int index) const {
  return render_order_.Get(index);
}
inline ::std::string* GameObject::mutable_render_order(int index) {
  return render_order_.Mutable(index);
}
inline void GameObject::set_render_order(int index, const ::std::string& value) {
  render_order_.Mutable(index)->assign(value);
}
inline void GameObject::set_render_order(int index, const char* value) {
  render_order_.Mutable(index)->assign(value);
}
inline void GameObject::set_render_order(int index, const char* value, size_t size) {
  render_order_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* GameObject::add_render_order() {
  return render_order_.Add();
}
inline void GameObject::add_render_order(const ::std::string& value) {
  render_order_.Add()->assign(value);
}
inline void GameObject::add_render_order(const char* value) {
  render_order_.Add()->assign(value);
}
inline void GameObject::add_render_order(const char* value, size_t size) {
  render_order_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
GameObject::render_order() const {
  return render_order_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
GameObject::mutable_render_order() {
  return &render_order_;
}

// optional .Serializer.ImageSprite imageSprite = 10;
inline bool GameObject::has_imagesprite() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void GameObject::set_has_imagesprite() {
  _has_bits_[0] |= 0x00000200u;
}
inline void GameObject::clear_has_imagesprite() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void GameObject::clear_imagesprite() {
  if (imagesprite_ != NULL) imagesprite_->::Serializer::ImageSprite::Clear();
  clear_has_imagesprite();
}
inline const ::Serializer::ImageSprite& GameObject::imagesprite() const {
  return imagesprite_ != NULL ? *imagesprite_ : *default_instance_->imagesprite_;
}
inline ::Serializer::ImageSprite* GameObject::mutable_imagesprite() {
  set_has_imagesprite();
  if (imagesprite_ == NULL) imagesprite_ = new ::Serializer::ImageSprite;
  return imagesprite_;
}
inline ::Serializer::ImageSprite* GameObject::release_imagesprite() {
  clear_has_imagesprite();
  ::Serializer::ImageSprite* temp = imagesprite_;
  imagesprite_ = NULL;
  return temp;
}

// optional .Serializer.ImageSprite9 imagesprite9 = 11;
inline bool GameObject::has_imagesprite9() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void GameObject::set_has_imagesprite9() {
  _has_bits_[0] |= 0x00000400u;
}
inline void GameObject::clear_has_imagesprite9() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void GameObject::clear_imagesprite9() {
  if (imagesprite9_ != NULL) imagesprite9_->::Serializer::ImageSprite9::Clear();
  clear_has_imagesprite9();
}
inline const ::Serializer::ImageSprite9& GameObject::imagesprite9() const {
  return imagesprite9_ != NULL ? *imagesprite9_ : *default_instance_->imagesprite9_;
}
inline ::Serializer::ImageSprite9* GameObject::mutable_imagesprite9() {
  set_has_imagesprite9();
  if (imagesprite9_ == NULL) imagesprite9_ = new ::Serializer::ImageSprite9;
  return imagesprite9_;
}
inline ::Serializer::ImageSprite9* GameObject::release_imagesprite9() {
  clear_has_imagesprite9();
  ::Serializer::ImageSprite9* temp = imagesprite9_;
  imagesprite9_ = NULL;
  return temp;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Serializer

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_GameObject_2eproto__INCLUDED
