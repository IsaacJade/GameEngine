// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: skelData.proto

#include "skelData.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr skelData_proto::skelData_proto(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : nodename_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , parentname_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , nodeindex_(0u)
  , parentindex_(0u){}
struct skelData_protoDefaultTypeInternal {
  constexpr skelData_protoDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~skelData_protoDefaultTypeInternal() {}
  union {
    skelData_proto _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT skelData_protoDefaultTypeInternal _skelData_proto_default_instance_;

// ===================================================================

class skelData_proto::_Internal {
 public:
  using HasBits = decltype(std::declval<skelData_proto>()._has_bits_);
  static void set_has_nodeindex(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_nodename(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_parentindex(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_parentname(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

skelData_proto::skelData_proto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:skelData_proto)
}
skelData_proto::skelData_proto(const skelData_proto& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  nodename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_nodename()) {
    nodename_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_nodename(), 
      GetArenaForAllocation());
  }
  parentname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_parentname()) {
    parentname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_parentname(), 
      GetArenaForAllocation());
  }
  ::memcpy(&nodeindex_, &from.nodeindex_,
    static_cast<size_t>(reinterpret_cast<char*>(&parentindex_) -
    reinterpret_cast<char*>(&nodeindex_)) + sizeof(parentindex_));
  // @@protoc_insertion_point(copy_constructor:skelData_proto)
}

inline void skelData_proto::SharedCtor() {
nodename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
parentname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&nodeindex_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&parentindex_) -
    reinterpret_cast<char*>(&nodeindex_)) + sizeof(parentindex_));
}

skelData_proto::~skelData_proto() {
  // @@protoc_insertion_point(destructor:skelData_proto)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

inline void skelData_proto::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  nodename_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  parentname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void skelData_proto::ArenaDtor(void* object) {
  skelData_proto* _this = reinterpret_cast< skelData_proto* >(object);
  (void)_this;
}
void skelData_proto::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void skelData_proto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void skelData_proto::Clear() {
// @@protoc_insertion_point(message_clear_start:skelData_proto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      nodename_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      parentname_.ClearNonDefaultToEmpty();
    }
  }
  if (cached_has_bits & 0x0000000cu) {
    ::memset(&nodeindex_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&parentindex_) -
        reinterpret_cast<char*>(&nodeindex_)) + sizeof(parentindex_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* skelData_proto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional uint32 nodeIndex = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_nodeindex(&has_bits);
          nodeindex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes nodeName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_nodename();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint32 parentIndex = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_parentindex(&has_bits);
          parentindex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes parentName = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_parentname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
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

::PROTOBUF_NAMESPACE_ID::uint8* skelData_proto::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:skelData_proto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // optional uint32 nodeIndex = 1;
  if (_internal_has_nodeindex()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_nodeindex(), target);
  }

  // optional bytes nodeName = 2;
  if (_internal_has_nodename()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_nodename(), target);
  }

  // optional uint32 parentIndex = 3;
  if (_internal_has_parentindex()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_parentindex(), target);
  }

  // optional bytes parentName = 4;
  if (_internal_has_parentname()) {
    target = stream->WriteBytesMaybeAliased(
        4, this->_internal_parentname(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:skelData_proto)
  return target;
}

size_t skelData_proto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:skelData_proto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    // optional bytes nodeName = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_nodename());
    }

    // optional bytes parentName = 4;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_parentname());
    }

    // optional uint32 nodeIndex = 1;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_nodeindex());
    }

    // optional uint32 parentIndex = 3;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_parentindex());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void skelData_proto::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const skelData_proto*>(
      &from));
}

void skelData_proto::MergeFrom(const skelData_proto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:skelData_proto)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_nodename(from._internal_nodename());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_parentname(from._internal_parentname());
    }
    if (cached_has_bits & 0x00000004u) {
      nodeindex_ = from.nodeindex_;
    }
    if (cached_has_bits & 0x00000008u) {
      parentindex_ = from.parentindex_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void skelData_proto::CopyFrom(const skelData_proto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:skelData_proto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool skelData_proto::IsInitialized() const {
  return true;
}

void skelData_proto::InternalSwap(skelData_proto* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &nodename_, GetArenaForAllocation(),
      &other->nodename_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &parentname_, GetArenaForAllocation(),
      &other->parentname_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(skelData_proto, parentindex_)
      + sizeof(skelData_proto::parentindex_)
      - PROTOBUF_FIELD_OFFSET(skelData_proto, nodeindex_)>(
          reinterpret_cast<char*>(&nodeindex_),
          reinterpret_cast<char*>(&other->nodeindex_));
}

std::string skelData_proto::GetTypeName() const {
  return "skelData_proto";
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::skelData_proto* Arena::CreateMaybeMessage< ::skelData_proto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::skelData_proto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
