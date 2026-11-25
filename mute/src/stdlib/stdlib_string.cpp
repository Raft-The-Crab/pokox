#include "poko/mute/stdlib_string.hpp"

#include <algorithm>
#include <array>
#include <cstdint>

namespace poko::mute {
namespace {
struct Decoded { std::uint32_t codepoint{0}; std::size_t bytes{0}; };

Decoded decode(std::string_view text, std::size_t at) noexcept {
  if (at >= text.size()) return {};
  const auto b0 = static_cast<std::uint8_t>(text[at]);
  if (b0 <= 0x7Fu) return {b0, 1};
  if (b0 >= 0xC2u && b0 <= 0xDFu) {
    if (at + 1 >= text.size()) return {};
    const auto b1 = static_cast<std::uint8_t>(text[at + 1]);
    if ((b1 & 0xC0u) != 0x80u) return {};
    return {static_cast<std::uint32_t>(((b0 & 0x1Fu) << 6) | (b1 & 0x3Fu)), 2};
  }
  if (b0 >= 0xE0u && b0 <= 0xEFu) {
    if (at + 2 >= text.size()) return {};
    const auto b1 = static_cast<std::uint8_t>(text[at + 1]);
    const auto b2 = static_cast<std::uint8_t>(text[at + 2]);
    if ((b1 & 0xC0u) != 0x80u || (b2 & 0xC0u) != 0x80u) return {};
    if (b0 == 0xE0u && b1 < 0xA0u) return {};
    if (b0 == 0xEDu && b1 > 0x9Fu) return {};
    return {static_cast<std::uint32_t>(((b0 & 0x0Fu) << 12) |
                                       ((b1 & 0x3Fu) << 6) | (b2 & 0x3Fu)), 3};
  }
  if (b0 >= 0xF0u && b0 <= 0xF4u) {
    if (at + 3 >= text.size()) return {};
    const auto b1 = static_cast<std::uint8_t>(text[at + 1]);
    const auto b2 = static_cast<std::uint8_t>(text[at + 2]);
    const auto b3 = static_cast<std::uint8_t>(text[at + 3]);
    if ((b1 & 0xC0u) != 0x80u || (b2 & 0xC0u) != 0x80u || (b3 & 0xC0u) != 0x80u) return {};
    if (b0 == 0xF0u && b1 < 0x90u) return {};
    if (b0 == 0xF4u && b1 > 0x8Fu) return {};
    return {static_cast<std::uint32_t>(((b0 & 0x07u) << 18) | ((b1 & 0x3Fu) << 12) |
                                       ((b2 & 0x3Fu) << 6) | (b3 & 0x3Fu)), 4};
  }
  return {};
}
}  // namespace

bool valid_utf8(std::string_view text) noexcept {
  std::size_t at = 0;
  while (at < text.size()) {
    const auto d = decode(text, at);
    if (d.bytes == 0) return false;
    at += d.bytes;
  }
  return true;
}

std::size_t byte_length(std::string_view text) noexcept { return text.size(); }

StringResult<std::size_t> codepoint_count(std::string_view text) noexcept {
  if (!valid_utf8(text)) return StringError::invalid_utf8;
  std::size_t count = 0;
  std::size_t at = 0;
  while (at < text.size()) at += decode(text, at).bytes, ++count;
  return count;
}

StringResult<std::string> slice_codepoints(std::string_view text, std::size_t first,
                                           std::size_t count) noexcept {
  if (!valid_utf8(text)) return StringError::invalid_utf8;
  std::size_t begin = 0, end = 0, index = 0;
  while (end < text.size()) {
    const auto d = decode(text, end);
    if (index == first) begin = end;
    end += d.bytes;
    if (index >= first && index - first + 1 == count) return std::string(text.substr(begin, end - begin));
    ++index;
  }
  if (count == 0 && first <= index) return std::string{};
  if (index == first) return std::string(text.substr(begin, end - begin));
  return StringError::out_of_range;
}

StringResult<std::string> concat(std::string_view a, std::string_view b) noexcept {
  if (a.size() + b.size() > max_stdlib_string_bytes) return StringError::size_limit;
  if (!valid_utf8(a) || !valid_utf8(b)) return StringError::invalid_utf8;
  std::string out;
  out.reserve(a.size() + b.size());
  out.append(a);
  out.append(b);
  return out;
}

int compare_bytes(std::string_view a, std::string_view b) noexcept {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

StringResult<std::size_t> find_bytes(std::string_view haystack, std::string_view needle) noexcept {
  if (needle.empty()) return std::size_t{0};
  const auto at = haystack.find(needle);
  if (at == std::string_view::npos) return StringError::out_of_range;
  return at;
}

StringResult<std::string> to_lower_ascii(std::string_view text) noexcept {
  if (!valid_utf8(text)) return StringError::invalid_utf8;
  std::string out(text);
  for (char& c : out)
    if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
  return out;
}

std::string_view name(StringError error) noexcept {
  switch (error) {
    case StringError::invalid_utf8: return "invalid_utf8";
    case StringError::out_of_range: return "out_of_range";
    case StringError::size_limit: return "size_limit";
  }
  return {};
}

}  // namespace poko::mute
