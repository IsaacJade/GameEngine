// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: modelData.proto

#include "modelData.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr modelData_proto::modelData_proto(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : skeldata_()
  , animdata_()
  , hierarchytable_()
  , _hierarchytable_cached_byte_size_(0)
  , pversion_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , pmodelname_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , meshdata_(nullptr)
  , porefsphere_(nullptr)
  , skelcount_(0u)
  , animcount_(0u){}
struct modelData_protoDefaultTypeInternal {
  constexpr modelData_protoDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~modelData_protoDefaultTypeInternal() {}
  union {
    modelData_proto _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT modelData_protoDefaultTypeInternal _modelData_proto_default_instance_;

// ===================================================================

class modelData_proto::_Internal {
 public:
  using HasBits = decltype(std::declval<modelData_proto>()._has_bits_);
  static void set_has_pversion(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_pmodelname(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static const ::meshData_proto& meshdata(const modelData_proto* msg);
  static void set_has_meshdata(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static const ::BoundingSphere_proto& porefsphere(const modelData_proto* msg);
  static void set_has_porefsphere(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_skelcount(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_animcount(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
};

const ::meshData_proto&
modelData_proto::_Internal::meshdata(const modelData_proto* msg) {
  return *msg->meshdata_;
}
const ::BoundingSphere_proto&
modelData_proto::_Internal::porefsphere(const modelData_proto* msg) {
  return *msg->porefsphere_;
}
void modelData_proto::clear_meshdata() {
  if (meshdata_ != nullptr) meshdata_->Clear();
  _has_bits_[0] &= ~0x00000004u;
}
void modelData_proto::clear_porefsphere() {
  if (porefsphere_ != nullptr) porefsphere_->Clear();
  _has_bits_[0] &= ~0x00000008u;
}
void modelData_proto::clear_skeldata() {
  skeldata_.Clear();
}
void modelData_proto::clear_animdata() {
  animdata_.Clear();
}
modelData_proto::modelData_proto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned),
  skeldata_(arena),
  animdata_(arena),
  hierarchytable_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:modelData_proto)
}
modelData_proto::modelData_proto(const modelData_proto& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_),
      skeldata_(from.skeldata_),
      animdata_(from.animdata_),
      hierarchytable_(from.hierarchytable_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  pversion_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_pversion()) {
    pversion_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_pversion(), 
      GetArenaForAllocation());
  }
  pmodelname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_pmodelname()) {
    pmodelname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_pmodelname(), 
      GetArenaForAllocation());
  }
  if (from._internal_has_meshdata()) {
    meshdata_ = new ::meshData_proto(*from.meshdata_);
  } else {
    meshdata_ = nullptr;
  }
  if (from._internal_has_porefsphere()) {
    porefsphere_ = new ::BoundingSphere_proto(*from.porefsphere_);
  } else {
    porefsphere_ = nullptr;
  }
  ::memcpy(&skelcount_, &from.skelcount_,
    static_cast<size_t>(reinterpret_cast<char*>(&animcount_) -
    reinterpret_cast<char*>(&skelcount_)) + sizeof(animcount_));
  // @@protoc_insertion_point(copy_constructor:modelData_proto)
}

inline void modelData_proto::SharedCtor() {
pversion_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
pmodelname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&meshdata_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&animcount_) -
    reinterpret_cast<char*>(&meshdata_)) + sizeof(animcount_));
}

modelData_proto::~modelData_proto() {
  // @@protoc_insertion_point(destructor:modelData_proto)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

inline void modelData_proto::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  pversion_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  pmodelname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete meshdata_;
  if (this != internal_default_instance()) delete porefsphere_;
}

void modelData_proto::ArenaDtor(void* object) {
  modelData_proto* _this = reinterpret_cast< modelData_proto* >(object);
  (void)_this;
}
void modelData_proto::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void modelData_proto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void modelData_proto::Clear() {
// @@protoc_insertion_point(message_clear_start:modelData_proto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  skeldata_.Clear();
  animdata_.Clear();
  hierarchytable_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      pversion_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      pmodelname_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(meshdata_ != nullptr);
      meshdata_->Clear();
    }
    if (cached_has_bits & 0x00000008u) {
      GOOGLE_DCHECK(porefsphere_ != nullptr);
      porefsphere_->Clear();
    }
  }
  if (cached_has_bits & 0x00000030u) {
    ::memset(&skelcount_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&animcount_) -
        reinterpret_cast<char*>(&skelcount_)) + sizeof(animcount_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* modelData_proto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional bytes pVersion = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_pversion();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes pModelName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_pmodelname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .meshData_proto meshData = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_meshdata(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .BoundingSphere_proto poRefSphere = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_porefsphere(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .skelData_proto skelData = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_skeldata(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else goto handle_unusual;
        continue;
      // optional uint32 skelCount = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          _Internal::set_has_skelcount(&has_bits);
          skelcount_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .animData_proto animData = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_animdata(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<58>(ptr));
        } else goto handle_unusual;
        continue;
      // optional uint32 animCount = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 64)) {
          _Internal::set_has_animcount(&has_bits);
          animcount_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated int32 hierarchyTable = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 74)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_hierarchytable(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 72) {
          _internal_add_hierarchytable(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* modelData_proto::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:modelData_proto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // optional bytes pVersion = 1;
  if (_internal_has_pversion()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_pversion(), target);
  }

  // optional bytes pModelName = 2;
  if (_internal_has_pmodelname()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_pmodelname(), target);
  }

  // optional .meshData_proto meshData = 3;
  if (_internal_has_meshdata()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        3, _Internal::meshdata(this), target, stream);
  }

  // optional .BoundingSphere_proto poRefSphere = 4;
  if (_internal_has_porefsphere()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::porefsphere(this), target, stream);
  }

  // repeated .skelData_proto skelData = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_skeldata_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, this->_internal_skeldata(i), target, stream);
  }

  // optional uint32 skelCount = 6;
  if (_internal_has_skelcount()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(6, this->_internal_skelcount(), target);
  }

  // repeated .animData_proto animData = 7;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_animdata_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(7, this->_internal_animdata(i), target, stream);
  }

  // optional uint32 animCount = 8;
  if (_internal_has_animcount()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(8, this->_internal_animcount(), target);
  }

  // repeated int32 hierarchyTable = 9;
  {
    int byte_size = _hierarchytable_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(
          9, _internal_hierarchytable(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:modelData_proto)
  return target;
}

size_t modelData_proto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:modelData_proto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .skelData_proto skelData = 5;
  total_size += 1UL * this->_internal_skeldata_size();
  for (const auto& msg : this->skeldata_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .animData_proto animData = 7;
  total_size += 1UL * this->_internal_animdata_size();
  for (const auto& msg : this->animdata_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated int32 hierarchyTable = 9;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int32Size(this->hierarchytable_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _hierarchytable_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    // optional bytes pVersion = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_pversion());
    }

    // optional bytes pModelName = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_pmodelname());
    }

    // optional .meshData_proto meshData = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *meshdata_);
    }

    // optional .BoundingSphere_proto poRefSphere = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *porefsphere_);
    }

    // optional uint32 skelCount = 6;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_skelcount());
    }

    // optional uint32 animCount = 8;
    if (cached_has_bits & 0x00000020u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_animcount());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void modelData_proto::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const modelData_proto*>(
      &from));
}

void modelData_proto::MergeFrom(const modelData_proto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:modelData_proto)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  skeldata_.MergeFrom(from.skeldata_);
  animdata_.MergeFrom(from.animdata_);
  hierarchytable_.MergeFrom(from.hierarchytable_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_pversion(from._internal_pversion());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_pmodelname(from._internal_pmodelname());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_mutable_meshdata()->::meshData_proto::MergeFrom(from._internal_meshdata());
    }
    if (cached_has_bits & 0x00000008u) {
      _internal_mutable_porefsphere()->::BoundingSphere_proto::MergeFrom(from._internal_porefsphere());
    }
    if (cached_has_bits & 0x00000010u) {
      skelcount_ = from.skelcount_;
    }
    if (cached_has_bits & 0x00000020u) {
      animcount_ = from.animcount_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void modelData_proto::CopyFrom(const modelData_proto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:modelData_proto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool modelData_proto::IsInitialized() const {
  return true;
}

void modelData_proto::InternalSwap(modelData_proto* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  skeldata_.InternalSwap(&other->skeldata_);
  animdata_.InternalSwap(&other->animdata_);
  hierarchytable_.InternalSwap(&other->hierarchytable_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &pversion_, GetArenaForAllocation(),
      &other->pversion_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &pmodelname_, GetArenaForAllocation(),
      &other->pmodelname_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(modelData_proto, animcount_)
      + sizeof(modelData_proto::animcount_)
      - PROTOBUF_FIELD_OFFSET(modelData_proto, meshdata_)>(
          reinterpret_cast<char*>(&meshdata_),
          reinterpret_cast<char*>(&other->meshdata_));
}

std::string modelData_proto::GetTypeName() const {
  return "modelData_proto";
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::modelData_proto* Arena::CreateMaybeMessage< ::modelData_proto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::modelData_proto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>