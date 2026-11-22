#include "poko/foundation/cbor.hpp"

#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>
#include <limits>

namespace poko::cbor {
namespace {
constexpr std::size_t kMaxDepth = 32;
constexpr std::size_t kMaxValues = 262144;

struct Cursor {
  const char* data;
  std::size_t size;
  std::size_t pos = 0;
  std::size_t values = 0;

  bool take(std::uint8_t& out) noexcept {
    if (pos >= size) return false;
    out = static_cast<std::uint8_t>(data[pos++]);
    return true;
  }
  bool take(std::uint64_t& out, unsigned count) noexcept {
    if (count > size - pos) return false;
    out = 0;
    for (unsigned i = 0; i < count; ++i) out = (out << 8) | static_cast<std::uint8_t>(data[pos++]);
    return true;
  }
  bool take_bytes(std::string& out, std::uint64_t length) noexcept {
    if (length > size - pos) return false;
    try {
      out.assign(data + pos, static_cast<std::size_t>(length));
    } catch (...) {
      return false;  // allocation failure — reported as truncated upstream
    }
    pos += static_cast<std::size_t>(length);
    return true;
  }
};

// Well-formed UTF-8 per RFC 3629 (rejects overlongs, surrogates, > U+10FFFF).
bool valid_utf8(const char* s, std::size_t n) noexcept {
  const auto* p = reinterpret_cast<const std::uint8_t*>(s);
  const auto* end = p + n;
  while (p < end) {
    const std::uint8_t c = *p;
    if (c < 0x80) { ++p; continue; }
    unsigned need, min;
    std::uint32_t cp;
    if ((c & 0xE0) == 0xC0) { need = 1; cp = c & 0x1F; min = 0x80; }
    else if ((c & 0xF0) == 0xE0) { need = 2; cp = c & 0x0F; min = 0x800; }
    else if ((c & 0xF8) == 0xF0) { need = 3; cp = c & 0x07; min = 0x10000; }
    else return false;
    if (end - p < static_cast<std::ptrdiff_t>(need + 1)) return false;
    for (unsigned i = 0; i < need; ++i) {
      const std::uint8_t t = p[1 + i];
      if ((t & 0xC0) != 0x80) return false;
      cp = (cp << 6) | (t & 0x3F);
    }
    if (cp < min || cp > 0x10FFFF || (cp >= 0xD800 && cp <= 0xDFFF)) return false;
    p += need + 1;
  }
  return true;
}

Result fail(Error error, std::size_t offset) noexcept {
  return {error, offset, {}};
}

// Read the additional-information argument for one item.
bool read_argument(Cursor& c, unsigned ai, std::uint64_t& arg) noexcept {
  if (ai < 24) { arg = ai; return true; }
  if (ai == 24) { std::uint8_t v; if (!c.take(v)) return false; arg = v; return true; }
  if (ai == 25) { std::uint64_t v; if (!c.take(v, 2)) return false; arg = v; return true; }
  if (ai == 26) { std::uint64_t v; if (!c.take(v, 4)) return false; arg = v; return true; }
  if (ai == 27) { std::uint64_t v; if (!c.take(v, 8)) return false; arg = v; return true; }
  return false;  // 28-30 reserved, 31 indefinite — caller maps to malformed/unsupported
}

double half_to_double(std::uint16_t h) noexcept {
  const unsigned sign = (h >> 15) & 1;
  const unsigned exp = (h >> 10) & 0x1F;
  const unsigned frac = h & 0x3FF;
  double value;
  if (exp == 0) value = std::ldexp(static_cast<double>(frac), -24);
  else if (exp == 31) value = frac ? std::numeric_limits<double>::quiet_NaN()
                                   : std::numeric_limits<double>::infinity();
  else value = std::ldexp(1.0 + static_cast<double>(frac) / 1024.0, static_cast<int>(exp) - 15);
  return sign ? -value : value;
}

Result decode_item(Cursor& c, Value& out, unsigned depth) noexcept {
  if (depth > kMaxDepth) return fail(Error::too_deep, c.pos);
  if (++c.values > kMaxValues) return fail(Error::too_many_items, c.pos);
  std::uint8_t initial;
  if (!c.take(initial)) return fail(Error::truncated, c.pos);
  const unsigned major = initial >> 5;
  const unsigned ai = initial & 0x1F;
  std::uint64_t arg = 0;
  // Major 7 reuses the low 5 bits for simple values and float widths, so its
  // payload is read in the branch below rather than as an argument.
  if (major != 7) {
    if (ai < 28) {
      if (!read_argument(c, ai, arg)) return fail(Error::truncated, c.pos);
    } else if (ai == 31) {
      return fail(Error::unsupported, c.pos - 1);  // indefinite length
    } else {
      return fail(Error::malformed, c.pos - 1);    // reserved additional info
    }
  } else if (ai == 31) {
    return fail(Error::unsupported, c.pos - 1);    // break code
  }
  switch (major) {
    case 0:
      out.type = Type::uint; out.u = arg; return {};
    case 1:
      out.type = Type::nint; out.u = arg;
      out.i = static_cast<std::int64_t>(std::uint64_t{0} - arg - 1);
      return {};
    case 2:
      out.type = Type::bytes;
      if (!c.take_bytes(out.string, arg)) return fail(Error::truncated, c.pos);
      return {};
    case 3:
      out.type = Type::text;
      if (!c.take_bytes(out.string, arg)) return fail(Error::truncated, c.pos);
      if (!valid_utf8(out.string.data(), out.string.size()))
        return fail(Error::invalid_utf8, c.pos - static_cast<std::size_t>(arg));
      return {};
    case 4: {
      out.type = Type::array;
      if (arg > kMaxValues) return fail(Error::too_many_items, c.pos);
      try {
        out.items.reserve(static_cast<std::size_t>(std::min<std::uint64_t>(arg, c.size - c.pos)));
      } catch (...) { return fail(Error::too_many_items, c.pos); }
      for (std::uint64_t i = 0; i < arg; ++i) {
        Value item;
        auto sub = decode_item(c, item, depth + 1);
        if (sub.error != Error::none) return sub;
        try { out.items.push_back(std::move(item)); }
        catch (...) { return fail(Error::too_many_items, c.pos); }
      }
      return {};
    }
    case 5: {
      out.type = Type::map;
      if (arg > kMaxValues) return fail(Error::too_many_items, c.pos);
      try {
        out.entries.reserve(static_cast<std::size_t>(std::min<std::uint64_t>(arg, c.size - c.pos)));
      } catch (...) { return fail(Error::too_many_items, c.pos); }
      for (std::uint64_t i = 0; i < arg; ++i) {
        Value key, val;
        auto sub = decode_item(c, key, depth + 1);
        if (sub.error != Error::none) return sub;
        sub = decode_item(c, val, depth + 1);
        if (sub.error != Error::none) return sub;
        try { out.entries.emplace_back(std::move(key), std::move(val)); }
        catch (...) { return fail(Error::too_many_items, c.pos); }
      }
      return {};
    }
    case 6:
      return fail(Error::unsupported, c.pos - 1);  // tags are not used by engine data
    default: {  // major 7 — simple values and floats
      if (ai == 20) { out.type = Type::boolean; out.boolean = false; return {}; }
      if (ai == 21) { out.type = Type::boolean; out.boolean = true; return {}; }
      if (ai == 22) { out.type = Type::null; return {}; }
      // ai 0-19/23/24 are simple values this decoder does not implement;
      // ai 28-30 are reserved.
      if (ai < 25 || ai > 27) {
        return fail(ai >= 28 ? Error::malformed : Error::unsupported, c.pos - 1);
      }
      const unsigned bytes = ai == 25 ? 2 : ai == 26 ? 4 : 8;
      std::uint64_t raw = 0;
      if (!c.take(raw, bytes)) return fail(Error::truncated, c.pos);
      out.type = Type::real;
      if (ai == 25) out.real = half_to_double(static_cast<std::uint16_t>(raw));
      else if (ai == 26) {
        const std::uint32_t bits = static_cast<std::uint32_t>(raw);
        float f;
        std::memcpy(&f, &bits, sizeof(f));
        out.real = f;
      } else {
        std::memcpy(&out.real, &raw, sizeof(out.real));
      }
      return {};
    }
  }
}
}  // namespace

Result decode(std::string_view input) noexcept {
  Cursor c{input.data(), input.size()};
  try {
    Result top;
    auto sub = decode_item(c, top.value, 0);
    if (sub.error != Error::none) return sub;
    if (c.pos != c.size) return fail(Error::malformed, c.pos);  // trailing bytes
    top.offset = c.pos;
    return top;
  } catch (...) {
    return fail(Error::too_many_items, c.pos);
  }
}

}  // namespace poko::cbor
