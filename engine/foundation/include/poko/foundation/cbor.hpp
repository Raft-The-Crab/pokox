#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace poko::cbor {

// Decode-only CBOR data model for engine data files (spec 21: foundation owns
// CBOR serialization). Canonical key ordering is a producer concern; this
// decoder accepts entries in any order and rejects indefinite-length items and
// tags, which canonical engine data never uses. Bounded: nesting is capped at
// 32 levels and the total value count at 262144 so hostile inputs stay cheap.
// The caller caps the input size (config files are limited to 1 MiB).
enum class Type : std::uint8_t {
  uint,       // Type::u holds the value
  nint,       // Type::u holds the raw argument; i holds -(u+1) wrapped to int64
  bytes,      // Type::string holds raw bytes (not necessarily UTF-8)
  text,       // Type::string holds validated UTF-8
  array,      // Type::items
  map,        // Type::entries (keys may be any type)
  boolean,    // Type::boolean
  null,
  real,       // Type::real (half/single/double all widen to double)
};

// Map entries cannot be std::pair<Value, Value>: pair is not an incomplete
// type, so naming it inside Value's own definition is ill-formed (Clang
// rejects it; GCC accepts by luck). Member is completed after Value.
struct Member;
struct Value {
  Type type = Type::null;
  std::uint64_t u = 0;
  std::int64_t i = 0;
  // optional so default-constructed Values allocate nothing: MSVC's debug STL
  // gives every std::string a heap proxy, which would let bad_alloc escape the
  // noexcept decode path. Engaged for Type::bytes and Type::text.
  std::optional<std::string> string;
  std::vector<Value> items;
  std::vector<Member> entries;
  bool boolean = false;
  double real = 0.0;
};
struct Member {
  Value first;
  Value second;
  Member(Value f, Value s) : first(std::move(f)), second(std::move(s)) {}
};

enum class Error : std::uint8_t {
  none,
  truncated,       // input ended mid-item
  malformed,       // reserved argument, bad structure
  unsupported,     // tag, indefinite length, unimplemented simple/float
  too_deep,        // nesting beyond the 32-level cap
  too_many_items,  // value count beyond the cap
  invalid_utf8,    // text string is not well-formed UTF-8
};

struct Result {
  Error error = Error::none;
  std::size_t offset = 0;  // byte offset of the failure, or input size on success
  Value value;
};

// Never throws; allocates only for the decoded tree.
[[nodiscard]] Result decode(std::string_view input) noexcept;

}  // namespace poko::cbor
