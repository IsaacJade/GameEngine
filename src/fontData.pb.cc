// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fontData.proto

#include "fontData.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr fontData_proto::fontData_proto(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : glyphs_()
  , text_font_(nullptr)
  , numglyph_(0u){}
struct fontData_protoDefaultTypeInternal {
  constexpr fontData_protoDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~fontData_protoDefaultTypeInternal() {}
  union {
    fontData_proto _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT fontData_protoDefaultTypeInternal _fontData_proto_default_instance_;

// ===================================================================

class fontData_proto::_Internal {
 public:
  using HasBits = decltype(std::declval<fontData_proto>()._has_bits_);
  static const ::textureData_proto& text_font(const fontData_proto* msg);
  static void set_has_text_font(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_numglyph(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

const ::textureData_proto&
fontData_proto::_Internal::text_font(const fontData_proto* msg) {
  return *msg->text_font_;
}
void fontData_proto::clear_text_font() {
  if (text_font_ != nullptr) text_font_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
void fontData_proto::clear_glyphs() {
  glyphs_.Clear();
}
fontData_proto::fontData_proto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned),
  glyphs_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:fontData_proto)
}
fontData_proto::fontData_proto(const fontData_proto& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_),
      glyphs_(from.glyphs_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  if (from._internal_has_text_font()) {
    text_font_ = new ::textureData_proto(*from.text_font_);
  } else {
    text_font_ = nullptr;
  }
  numglyph_ = from.numglyph_;
  // @@protoc_insertion_point(copy_constructor:fontData_proto)
}

inline void fontData_proto::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&text_font_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&numglyph_) -
    reinterpret_cast<char*>(&text_font_)) + sizeof(numglyph_));
}

fontData_proto::~fontData_proto() {
  // @@protoc_insertion_point(destructor:fontData_proto)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

inline void fontData_proto::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete text_font_;
}

void fontData_proto::ArenaDtor(void* object) {
  fontData_proto* _this = reinterpret_cast< fontData_proto* >(object);
  (void)_this;
}
void fontData_proto::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void fontData_proto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void fontData_proto::Clear() {
// @@protoc_insertion_point(message_clear_start:fontData_proto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  glyphs_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(text_font_ != nullptr);
    text_font_->Clear();
  }
  numglyph_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* fontData_proto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional .textureData_proto text_font = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_text_font(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint32 numGlyph = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_numglyph(&has_bits);
          numglyph_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .glyphData_proto glyphs = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_glyphs(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* fontData_proto::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:fontData_proto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // optional .textureData_proto text_font = 1;
  if (_internal_has_text_font()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::text_font(this), target, stream);
  }

  // optional uint32 numGlyph = 2;
  if (_internal_has_numglyph()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_numglyph(), target);
  }

  // repeated .glyphData_proto glyphs = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_glyphs_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_glyphs(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fontData_proto)
  return target;
}

size_t fontData_proto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:fontData_proto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .glyphData_proto glyphs = 3;
  total_size += 1UL * this->_internal_glyphs_size();
  for (const auto& msg : this->glyphs_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional .textureData_proto text_font = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *text_font_);
    }

    // optional uint32 numGlyph = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_numglyph());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void fontData_proto::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const fontData_proto*>(
      &from));
}

void fontData_proto::MergeFrom(const fontData_proto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:fontData_proto)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  glyphs_.MergeFrom(from.glyphs_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_text_font()->::textureData_proto::MergeFrom(from._internal_text_font());
    }
    if (cached_has_bits & 0x00000002u) {
      numglyph_ = from.numglyph_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void fontData_proto::CopyFrom(const fontData_proto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fontData_proto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool fontData_proto::IsInitialized() const {
  return true;
}

void fontData_proto::InternalSwap(fontData_proto* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  glyphs_.InternalSwap(&other->glyphs_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(fontData_proto, numglyph_)
      + sizeof(fontData_proto::numglyph_)
      - PROTOBUF_FIELD_OFFSET(fontData_proto, text_font_)>(
          reinterpret_cast<char*>(&text_font_),
          reinterpret_cast<char*>(&other->text_font_));
}

std::string fontData_proto::GetTypeName() const {
  return "fontData_proto";
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::fontData_proto* Arena::CreateMaybeMessage< ::fontData_proto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::fontData_proto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
