// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: modelData.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_modelData_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_modelData_2eproto

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
#include "meshData.pb.h"
#include "BoundingSphere.pb.h"
#include "skelData.pb.h"
#include "animData.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_modelData_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_modelData_2eproto {
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
class modelData_proto;
struct modelData_protoDefaultTypeInternal;
extern modelData_protoDefaultTypeInternal _modelData_proto_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::modelData_proto* Arena::CreateMaybeMessage<::modelData_proto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class modelData_proto final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:modelData_proto) */ {
 public:
  inline modelData_proto() : modelData_proto(nullptr) {}
  ~modelData_proto() override;
  explicit constexpr modelData_proto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  modelData_proto(const modelData_proto& from);
  modelData_proto(modelData_proto&& from) noexcept
    : modelData_proto() {
    *this = ::std::move(from);
  }

  inline modelData_proto& operator=(const modelData_proto& from) {
    CopyFrom(from);
    return *this;
  }
  inline modelData_proto& operator=(modelData_proto&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const modelData_proto& default_instance() {
    return *internal_default_instance();
  }
  static inline const modelData_proto* internal_default_instance() {
    return reinterpret_cast<const modelData_proto*>(
               &_modelData_proto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(modelData_proto& a, modelData_proto& b) {
    a.Swap(&b);
  }
  inline void Swap(modelData_proto* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(modelData_proto* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline modelData_proto* New() const final {
    return new modelData_proto();
  }

  modelData_proto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<modelData_proto>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const modelData_proto& from);
  void MergeFrom(const modelData_proto& from);
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
  void InternalSwap(modelData_proto* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "modelData_proto";
  }
  protected:
  explicit modelData_proto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSkelDataFieldNumber = 5,
    kAnimDataFieldNumber = 7,
    kHierarchyTableFieldNumber = 9,
    kPVersionFieldNumber = 1,
    kPModelNameFieldNumber = 2,
    kMeshDataFieldNumber = 3,
    kPoRefSphereFieldNumber = 4,
    kSkelCountFieldNumber = 6,
    kAnimCountFieldNumber = 8,
  };
  // repeated .skelData_proto skelData = 5;
  int skeldata_size() const;
  private:
  int _internal_skeldata_size() const;
  public:
  void clear_skeldata();
  ::skelData_proto* mutable_skeldata(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skelData_proto >*
      mutable_skeldata();
  private:
  const ::skelData_proto& _internal_skeldata(int index) const;
  ::skelData_proto* _internal_add_skeldata();
  public:
  const ::skelData_proto& skeldata(int index) const;
  ::skelData_proto* add_skeldata();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skelData_proto >&
      skeldata() const;

  // repeated .animData_proto animData = 7;
  int animdata_size() const;
  private:
  int _internal_animdata_size() const;
  public:
  void clear_animdata();
  ::animData_proto* mutable_animdata(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::animData_proto >*
      mutable_animdata();
  private:
  const ::animData_proto& _internal_animdata(int index) const;
  ::animData_proto* _internal_add_animdata();
  public:
  const ::animData_proto& animdata(int index) const;
  ::animData_proto* add_animdata();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::animData_proto >&
      animdata() const;

  // repeated int32 hierarchyTable = 9;
  int hierarchytable_size() const;
  private:
  int _internal_hierarchytable_size() const;
  public:
  void clear_hierarchytable();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_hierarchytable(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_hierarchytable() const;
  void _internal_add_hierarchytable(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_hierarchytable();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 hierarchytable(int index) const;
  void set_hierarchytable(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_hierarchytable(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      hierarchytable() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_hierarchytable();

  // optional bytes pVersion = 1;
  bool has_pversion() const;
  private:
  bool _internal_has_pversion() const;
  public:
  void clear_pversion();
  const std::string& pversion() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_pversion(ArgT0&& arg0, ArgT... args);
  std::string* mutable_pversion();
  PROTOBUF_MUST_USE_RESULT std::string* release_pversion();
  void set_allocated_pversion(std::string* pversion);
  private:
  const std::string& _internal_pversion() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_pversion(const std::string& value);
  std::string* _internal_mutable_pversion();
  public:

  // optional bytes pModelName = 2;
  bool has_pmodelname() const;
  private:
  bool _internal_has_pmodelname() const;
  public:
  void clear_pmodelname();
  const std::string& pmodelname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_pmodelname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_pmodelname();
  PROTOBUF_MUST_USE_RESULT std::string* release_pmodelname();
  void set_allocated_pmodelname(std::string* pmodelname);
  private:
  const std::string& _internal_pmodelname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_pmodelname(const std::string& value);
  std::string* _internal_mutable_pmodelname();
  public:

  // optional .meshData_proto meshData = 3;
  bool has_meshdata() const;
  private:
  bool _internal_has_meshdata() const;
  public:
  void clear_meshdata();
  const ::meshData_proto& meshdata() const;
  PROTOBUF_MUST_USE_RESULT ::meshData_proto* release_meshdata();
  ::meshData_proto* mutable_meshdata();
  void set_allocated_meshdata(::meshData_proto* meshdata);
  private:
  const ::meshData_proto& _internal_meshdata() const;
  ::meshData_proto* _internal_mutable_meshdata();
  public:
  void unsafe_arena_set_allocated_meshdata(
      ::meshData_proto* meshdata);
  ::meshData_proto* unsafe_arena_release_meshdata();

  // optional .BoundingSphere_proto poRefSphere = 4;
  bool has_porefsphere() const;
  private:
  bool _internal_has_porefsphere() const;
  public:
  void clear_porefsphere();
  const ::BoundingSphere_proto& porefsphere() const;
  PROTOBUF_MUST_USE_RESULT ::BoundingSphere_proto* release_porefsphere();
  ::BoundingSphere_proto* mutable_porefsphere();
  void set_allocated_porefsphere(::BoundingSphere_proto* porefsphere);
  private:
  const ::BoundingSphere_proto& _internal_porefsphere() const;
  ::BoundingSphere_proto* _internal_mutable_porefsphere();
  public:
  void unsafe_arena_set_allocated_porefsphere(
      ::BoundingSphere_proto* porefsphere);
  ::BoundingSphere_proto* unsafe_arena_release_porefsphere();

  // optional uint32 skelCount = 6;
  bool has_skelcount() const;
  private:
  bool _internal_has_skelcount() const;
  public:
  void clear_skelcount();
  ::PROTOBUF_NAMESPACE_ID::uint32 skelcount() const;
  void set_skelcount(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_skelcount() const;
  void _internal_set_skelcount(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // optional uint32 animCount = 8;
  bool has_animcount() const;
  private:
  bool _internal_has_animcount() const;
  public:
  void clear_animcount();
  ::PROTOBUF_NAMESPACE_ID::uint32 animcount() const;
  void set_animcount(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_animcount() const;
  void _internal_set_animcount(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:modelData_proto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skelData_proto > skeldata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::animData_proto > animdata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > hierarchytable_;
  mutable std::atomic<int> _hierarchytable_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pversion_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pmodelname_;
  ::meshData_proto* meshdata_;
  ::BoundingSphere_proto* porefsphere_;
  ::PROTOBUF_NAMESPACE_ID::uint32 skelcount_;
  ::PROTOBUF_NAMESPACE_ID::uint32 animcount_;
  friend struct ::TableStruct_modelData_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// modelData_proto

// optional bytes pVersion = 1;
inline bool modelData_proto::_internal_has_pversion() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool modelData_proto::has_pversion() const {
  return _internal_has_pversion();
}
inline void modelData_proto::clear_pversion() {
  pversion_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& modelData_proto::pversion() const {
  // @@protoc_insertion_point(field_get:modelData_proto.pVersion)
  return _internal_pversion();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void modelData_proto::set_pversion(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 pversion_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:modelData_proto.pVersion)
}
inline std::string* modelData_proto::mutable_pversion() {
  std::string* _s = _internal_mutable_pversion();
  // @@protoc_insertion_point(field_mutable:modelData_proto.pVersion)
  return _s;
}
inline const std::string& modelData_proto::_internal_pversion() const {
  return pversion_.Get();
}
inline void modelData_proto::_internal_set_pversion(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  pversion_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* modelData_proto::_internal_mutable_pversion() {
  _has_bits_[0] |= 0x00000001u;
  return pversion_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* modelData_proto::release_pversion() {
  // @@protoc_insertion_point(field_release:modelData_proto.pVersion)
  if (!_internal_has_pversion()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return pversion_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void modelData_proto::set_allocated_pversion(std::string* pversion) {
  if (pversion != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  pversion_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pversion,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:modelData_proto.pVersion)
}

// optional bytes pModelName = 2;
inline bool modelData_proto::_internal_has_pmodelname() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool modelData_proto::has_pmodelname() const {
  return _internal_has_pmodelname();
}
inline void modelData_proto::clear_pmodelname() {
  pmodelname_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& modelData_proto::pmodelname() const {
  // @@protoc_insertion_point(field_get:modelData_proto.pModelName)
  return _internal_pmodelname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void modelData_proto::set_pmodelname(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000002u;
 pmodelname_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:modelData_proto.pModelName)
}
inline std::string* modelData_proto::mutable_pmodelname() {
  std::string* _s = _internal_mutable_pmodelname();
  // @@protoc_insertion_point(field_mutable:modelData_proto.pModelName)
  return _s;
}
inline const std::string& modelData_proto::_internal_pmodelname() const {
  return pmodelname_.Get();
}
inline void modelData_proto::_internal_set_pmodelname(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  pmodelname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* modelData_proto::_internal_mutable_pmodelname() {
  _has_bits_[0] |= 0x00000002u;
  return pmodelname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* modelData_proto::release_pmodelname() {
  // @@protoc_insertion_point(field_release:modelData_proto.pModelName)
  if (!_internal_has_pmodelname()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return pmodelname_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void modelData_proto::set_allocated_pmodelname(std::string* pmodelname) {
  if (pmodelname != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  pmodelname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pmodelname,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:modelData_proto.pModelName)
}

// optional .meshData_proto meshData = 3;
inline bool modelData_proto::_internal_has_meshdata() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  PROTOBUF_ASSUME(!value || meshdata_ != nullptr);
  return value;
}
inline bool modelData_proto::has_meshdata() const {
  return _internal_has_meshdata();
}
inline const ::meshData_proto& modelData_proto::_internal_meshdata() const {
  const ::meshData_proto* p = meshdata_;
  return p != nullptr ? *p : reinterpret_cast<const ::meshData_proto&>(
      ::_meshData_proto_default_instance_);
}
inline const ::meshData_proto& modelData_proto::meshdata() const {
  // @@protoc_insertion_point(field_get:modelData_proto.meshData)
  return _internal_meshdata();
}
inline void modelData_proto::unsafe_arena_set_allocated_meshdata(
    ::meshData_proto* meshdata) {
  if (GetArenaForAllocation() == nullptr) {
    delete static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(meshdata_);
  }
  meshdata_ = meshdata;
  if (meshdata) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:modelData_proto.meshData)
}
inline ::meshData_proto* modelData_proto::release_meshdata() {
  _has_bits_[0] &= ~0x00000004u;
  ::meshData_proto* temp = meshdata_;
  meshdata_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::meshData_proto* modelData_proto::unsafe_arena_release_meshdata() {
  // @@protoc_insertion_point(field_release:modelData_proto.meshData)
  _has_bits_[0] &= ~0x00000004u;
  ::meshData_proto* temp = meshdata_;
  meshdata_ = nullptr;
  return temp;
}
inline ::meshData_proto* modelData_proto::_internal_mutable_meshdata() {
  _has_bits_[0] |= 0x00000004u;
  if (meshdata_ == nullptr) {
    auto* p = CreateMaybeMessage<::meshData_proto>(GetArenaForAllocation());
    meshdata_ = p;
  }
  return meshdata_;
}
inline ::meshData_proto* modelData_proto::mutable_meshdata() {
  ::meshData_proto* _msg = _internal_mutable_meshdata();
  // @@protoc_insertion_point(field_mutable:modelData_proto.meshData)
  return _msg;
}
inline void modelData_proto::set_allocated_meshdata(::meshData_proto* meshdata) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete static_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(meshdata_);
  }
  if (meshdata) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(meshdata));
    if (message_arena != submessage_arena) {
      meshdata = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, meshdata, submessage_arena);
    }
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  meshdata_ = meshdata;
  // @@protoc_insertion_point(field_set_allocated:modelData_proto.meshData)
}

// optional .BoundingSphere_proto poRefSphere = 4;
inline bool modelData_proto::_internal_has_porefsphere() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  PROTOBUF_ASSUME(!value || porefsphere_ != nullptr);
  return value;
}
inline bool modelData_proto::has_porefsphere() const {
  return _internal_has_porefsphere();
}
inline const ::BoundingSphere_proto& modelData_proto::_internal_porefsphere() const {
  const ::BoundingSphere_proto* p = porefsphere_;
  return p != nullptr ? *p : reinterpret_cast<const ::BoundingSphere_proto&>(
      ::_BoundingSphere_proto_default_instance_);
}
inline const ::BoundingSphere_proto& modelData_proto::porefsphere() const {
  // @@protoc_insertion_point(field_get:modelData_proto.poRefSphere)
  return _internal_porefsphere();
}
inline void modelData_proto::unsafe_arena_set_allocated_porefsphere(
    ::BoundingSphere_proto* porefsphere) {
  if (GetArenaForAllocation() == nullptr) {
    delete static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(porefsphere_);
  }
  porefsphere_ = porefsphere;
  if (porefsphere) {
    _has_bits_[0] |= 0x00000008u;
  } else {
    _has_bits_[0] &= ~0x00000008u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:modelData_proto.poRefSphere)
}
inline ::BoundingSphere_proto* modelData_proto::release_porefsphere() {
  _has_bits_[0] &= ~0x00000008u;
  ::BoundingSphere_proto* temp = porefsphere_;
  porefsphere_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::BoundingSphere_proto* modelData_proto::unsafe_arena_release_porefsphere() {
  // @@protoc_insertion_point(field_release:modelData_proto.poRefSphere)
  _has_bits_[0] &= ~0x00000008u;
  ::BoundingSphere_proto* temp = porefsphere_;
  porefsphere_ = nullptr;
  return temp;
}
inline ::BoundingSphere_proto* modelData_proto::_internal_mutable_porefsphere() {
  _has_bits_[0] |= 0x00000008u;
  if (porefsphere_ == nullptr) {
    auto* p = CreateMaybeMessage<::BoundingSphere_proto>(GetArenaForAllocation());
    porefsphere_ = p;
  }
  return porefsphere_;
}
inline ::BoundingSphere_proto* modelData_proto::mutable_porefsphere() {
  ::BoundingSphere_proto* _msg = _internal_mutable_porefsphere();
  // @@protoc_insertion_point(field_mutable:modelData_proto.poRefSphere)
  return _msg;
}
inline void modelData_proto::set_allocated_porefsphere(::BoundingSphere_proto* porefsphere) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete static_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(porefsphere_);
  }
  if (porefsphere) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(porefsphere));
    if (message_arena != submessage_arena) {
      porefsphere = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, porefsphere, submessage_arena);
    }
    _has_bits_[0] |= 0x00000008u;
  } else {
    _has_bits_[0] &= ~0x00000008u;
  }
  porefsphere_ = porefsphere;
  // @@protoc_insertion_point(field_set_allocated:modelData_proto.poRefSphere)
}

// repeated .skelData_proto skelData = 5;
inline int modelData_proto::_internal_skeldata_size() const {
  return skeldata_.size();
}
inline int modelData_proto::skeldata_size() const {
  return _internal_skeldata_size();
}
inline ::skelData_proto* modelData_proto::mutable_skeldata(int index) {
  // @@protoc_insertion_point(field_mutable:modelData_proto.skelData)
  return skeldata_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skelData_proto >*
modelData_proto::mutable_skeldata() {
  // @@protoc_insertion_point(field_mutable_list:modelData_proto.skelData)
  return &skeldata_;
}
inline const ::skelData_proto& modelData_proto::_internal_skeldata(int index) const {
  return skeldata_.Get(index);
}
inline const ::skelData_proto& modelData_proto::skeldata(int index) const {
  // @@protoc_insertion_point(field_get:modelData_proto.skelData)
  return _internal_skeldata(index);
}
inline ::skelData_proto* modelData_proto::_internal_add_skeldata() {
  return skeldata_.Add();
}
inline ::skelData_proto* modelData_proto::add_skeldata() {
  ::skelData_proto* _add = _internal_add_skeldata();
  // @@protoc_insertion_point(field_add:modelData_proto.skelData)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skelData_proto >&
modelData_proto::skeldata() const {
  // @@protoc_insertion_point(field_list:modelData_proto.skelData)
  return skeldata_;
}

// optional uint32 skelCount = 6;
inline bool modelData_proto::_internal_has_skelcount() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool modelData_proto::has_skelcount() const {
  return _internal_has_skelcount();
}
inline void modelData_proto::clear_skelcount() {
  skelcount_ = 0u;
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 modelData_proto::_internal_skelcount() const {
  return skelcount_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 modelData_proto::skelcount() const {
  // @@protoc_insertion_point(field_get:modelData_proto.skelCount)
  return _internal_skelcount();
}
inline void modelData_proto::_internal_set_skelcount(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000010u;
  skelcount_ = value;
}
inline void modelData_proto::set_skelcount(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_skelcount(value);
  // @@protoc_insertion_point(field_set:modelData_proto.skelCount)
}

// repeated .animData_proto animData = 7;
inline int modelData_proto::_internal_animdata_size() const {
  return animdata_.size();
}
inline int modelData_proto::animdata_size() const {
  return _internal_animdata_size();
}
inline ::animData_proto* modelData_proto::mutable_animdata(int index) {
  // @@protoc_insertion_point(field_mutable:modelData_proto.animData)
  return animdata_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::animData_proto >*
modelData_proto::mutable_animdata() {
  // @@protoc_insertion_point(field_mutable_list:modelData_proto.animData)
  return &animdata_;
}
inline const ::animData_proto& modelData_proto::_internal_animdata(int index) const {
  return animdata_.Get(index);
}
inline const ::animData_proto& modelData_proto::animdata(int index) const {
  // @@protoc_insertion_point(field_get:modelData_proto.animData)
  return _internal_animdata(index);
}
inline ::animData_proto* modelData_proto::_internal_add_animdata() {
  return animdata_.Add();
}
inline ::animData_proto* modelData_proto::add_animdata() {
  ::animData_proto* _add = _internal_add_animdata();
  // @@protoc_insertion_point(field_add:modelData_proto.animData)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::animData_proto >&
modelData_proto::animdata() const {
  // @@protoc_insertion_point(field_list:modelData_proto.animData)
  return animdata_;
}

// optional uint32 animCount = 8;
inline bool modelData_proto::_internal_has_animcount() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool modelData_proto::has_animcount() const {
  return _internal_has_animcount();
}
inline void modelData_proto::clear_animcount() {
  animcount_ = 0u;
  _has_bits_[0] &= ~0x00000020u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 modelData_proto::_internal_animcount() const {
  return animcount_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 modelData_proto::animcount() const {
  // @@protoc_insertion_point(field_get:modelData_proto.animCount)
  return _internal_animcount();
}
inline void modelData_proto::_internal_set_animcount(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000020u;
  animcount_ = value;
}
inline void modelData_proto::set_animcount(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_animcount(value);
  // @@protoc_insertion_point(field_set:modelData_proto.animCount)
}

// repeated int32 hierarchyTable = 9;
inline int modelData_proto::_internal_hierarchytable_size() const {
  return hierarchytable_.size();
}
inline int modelData_proto::hierarchytable_size() const {
  return _internal_hierarchytable_size();
}
inline void modelData_proto::clear_hierarchytable() {
  hierarchytable_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 modelData_proto::_internal_hierarchytable(int index) const {
  return hierarchytable_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 modelData_proto::hierarchytable(int index) const {
  // @@protoc_insertion_point(field_get:modelData_proto.hierarchyTable)
  return _internal_hierarchytable(index);
}
inline void modelData_proto::set_hierarchytable(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  hierarchytable_.Set(index, value);
  // @@protoc_insertion_point(field_set:modelData_proto.hierarchyTable)
}
inline void modelData_proto::_internal_add_hierarchytable(::PROTOBUF_NAMESPACE_ID::int32 value) {
  hierarchytable_.Add(value);
}
inline void modelData_proto::add_hierarchytable(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_hierarchytable(value);
  // @@protoc_insertion_point(field_add:modelData_proto.hierarchyTable)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
modelData_proto::_internal_hierarchytable() const {
  return hierarchytable_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
modelData_proto::hierarchytable() const {
  // @@protoc_insertion_point(field_list:modelData_proto.hierarchyTable)
  return _internal_hierarchytable();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
modelData_proto::_internal_mutable_hierarchytable() {
  return &hierarchytable_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
modelData_proto::mutable_hierarchytable() {
  // @@protoc_insertion_point(field_mutable_list:modelData_proto.hierarchyTable)
  return _internal_mutable_hierarchytable();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_modelData_2eproto
