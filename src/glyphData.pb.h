// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: glyphData.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_glyphData_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_glyphData_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_glyphData_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_glyphData_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
class glyphData_proto;
struct glyphData_protoDefaultTypeInternal;
extern glyphData_protoDefaultTypeInternal _glyphData_proto_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::glyphData_proto* Arena::CreateMaybeMessage<::glyphData_proto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class glyphData_proto final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:glyphData_proto) */ {
 public:
  inline glyphData_proto() : glyphData_proto(nullptr) {}
  ~glyphData_proto() override;
  explicit constexpr glyphData_proto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  glyphData_proto(const glyphData_proto& from);
  glyphData_proto(glyphData_proto&& from) noexcept
    : glyphData_proto() {
    *this = ::std::move(from);
  }

  inline glyphData_proto& operator=(const glyphData_proto& from) {
    CopyFrom(from);
    return *this;
  }
  inline glyphData_proto& operator=(glyphData_proto&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const glyphData_proto& default_instance() {
    return *internal_default_instance();
  }
  static inline const glyphData_proto* internal_default_instance() {
    return reinterpret_cast<const glyphData_proto*>(
               &_glyphData_proto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(glyphData_proto& a, glyphData_proto& b) {
    a.Swap(&b);
  }
  inline void Swap(glyphData_proto* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(glyphData_proto* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline glyphData_proto* New() const final {
    return new glyphData_proto();
  }

  glyphData_proto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<glyphData_proto>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const glyphData_proto& from);
  void MergeFrom(const glyphData_proto& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(glyphData_proto* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "glyphData_proto";
  }
  protected:
  explicit glyphData_proto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kKeyFieldNumber = 1,
    kXFieldNumber = 2,
    kYFieldNumber = 3,
    kWidthFieldNumber = 4,
    kHeightFieldNumber = 5,
  };
  // float key = 1;
  void clear_key();
  float key() const;
  void set_key(float value);
  private:
  float _internal_key() const;
  void _internal_set_key(float value);
  public:

  // float x = 2;
  void clear_x();
  float x() const;
  void set_x(float value);
  private:
  float _internal_x() const;
  void _internal_set_x(float value);
  public:

  // float y = 3;
  void clear_y();
  float y() const;
  void set_y(float value);
  private:
  float _internal_y() const;
  void _internal_set_y(float value);
  public:

  // float width = 4;
  void clear_width();
  float width() const;
  void set_width(float value);
  private:
  float _internal_width() const;
  void _internal_set_width(float value);
  public:

  // float height = 5;
  void clear_height();
  float height() const;
  void set_height(float value);
  private:
  float _internal_height() const;
  void _internal_set_height(float value);
  public:

  // @@protoc_insertion_point(class_scope:glyphData_proto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  float key_;
  float x_;
  float y_;
  float width_;
  float height_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_glyphData_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// glyphData_proto

// float key = 1;
inline void glyphData_proto::clear_key() {
  key_ = 0;
}
inline float glyphData_proto::_internal_key() const {
  return key_;
}
inline float glyphData_proto::key() const {
  // @@protoc_insertion_point(field_get:glyphData_proto.key)
  return _internal_key();
}
inline void glyphData_proto::_internal_set_key(float value) {
  
  key_ = value;
}
inline void glyphData_proto::set_key(float value) {
  _internal_set_key(value);
  // @@protoc_insertion_point(field_set:glyphData_proto.key)
}

// float x = 2;
inline void glyphData_proto::clear_x() {
  x_ = 0;
}
inline float glyphData_proto::_internal_x() const {
  return x_;
}
inline float glyphData_proto::x() const {
  // @@protoc_insertion_point(field_get:glyphData_proto.x)
  return _internal_x();
}
inline void glyphData_proto::_internal_set_x(float value) {
  
  x_ = value;
}
inline void glyphData_proto::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:glyphData_proto.x)
}

// float y = 3;
inline void glyphData_proto::clear_y() {
  y_ = 0;
}
inline float glyphData_proto::_internal_y() const {
  return y_;
}
inline float glyphData_proto::y() const {
  // @@protoc_insertion_point(field_get:glyphData_proto.y)
  return _internal_y();
}
inline void glyphData_proto::_internal_set_y(float value) {
  
  y_ = value;
}
inline void glyphData_proto::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:glyphData_proto.y)
}

// float width = 4;
inline void glyphData_proto::clear_width() {
  width_ = 0;
}
inline float glyphData_proto::_internal_width() const {
  return width_;
}
inline float glyphData_proto::width() const {
  // @@protoc_insertion_point(field_get:glyphData_proto.width)
  return _internal_width();
}
inline void glyphData_proto::_internal_set_width(float value) {
  
  width_ = value;
}
inline void glyphData_proto::set_width(float value) {
  _internal_set_width(value);
  // @@protoc_insertion_point(field_set:glyphData_proto.width)
}

// float height = 5;
inline void glyphData_proto::clear_height() {
  height_ = 0;
}
inline float glyphData_proto::_internal_height() const {
  return height_;
}
inline float glyphData_proto::height() const {
  // @@protoc_insertion_point(field_get:glyphData_proto.height)
  return _internal_height();
}
inline void glyphData_proto::_internal_set_height(float value) {
  
  height_ = value;
}
inline void glyphData_proto::set_height(float value) {
  _internal_set_height(value);
  // @@protoc_insertion_point(field_set:glyphData_proto.height)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_glyphData_2eproto
