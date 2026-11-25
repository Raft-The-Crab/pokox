#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include <variant>

namespace poko::mute {

// MUT-52: host-side string operations. v1 uses canonical UTF-8 only. There is
// no locale, normalization, collation or Unicode case folding: ordering is
// bytewise and ASCII lowercasing is explicit. Invalid UTF-8 never enters a
// validated result.
enum class StringError { invalid_utf8, out_of_range, size_limit };

template <class T>
using StringResult = std::variant<T, StringError>;

inline constexpr std::size_t max_stdlib_string_bytes = 64u * 1024u * 1024u;

[[nodiscard]] bool valid_utf8(std::string_view text) noexcept;
[[nodiscard]] std::size_t byte_length(std::string_view text) noexcept;
[[nodiscard]] StringResult<std::size_t> codepoint_count(std::string_view text) noexcept;
[[nodiscard]] StringResult<std::string> slice_codepoints(std::string_view text,
                                                         std::size_t first,
                                                         std::size_t count) noexcept;
[[nodiscard]] StringResult<std::string> concat(std::string_view a, std::string_view b) noexcept;
[[nodiscard]] int compare_bytes(std::string_view a, std::string_view b) noexcept;
[[nodiscard]] StringResult<std::size_t> find_bytes(std::string_view haystack,
                                                   std::string_view needle) noexcept;
[[nodiscard]] StringResult<std::string> to_lower_ascii(std::string_view text) noexcept;
[[nodiscard]] std::string_view name(StringError error) noexcept;

}  // namespace poko::mute
