#pragma once

// Build-only compatibility shim for the pinned Android NDK r22 libc++.
// It supplies std::bit_cast and floating-point std::from_chars, which the
// repository's portable C++20 sources use but that NDK libc++ lacks.
// Repo sources are unchanged; the dual-target runner injects this header
// with -include only for Android CLI gate binaries.

#include <cerrno>
#include <charconv>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>

#if !defined(__cpp_lib_bit_cast) || __cpp_lib_bit_cast < 201806L
namespace std {
template <class To, class From>
constexpr To bit_cast(const From& from) noexcept {
  static_assert(sizeof(To) == sizeof(From), "bit_cast size mismatch");
  static_assert(is_trivially_copyable_v<To> && is_trivially_copyable_v<From>,
                "bit_cast requires trivially copyable types");
  To to{};
  memcpy(&to, &from, sizeof(To));
  return to;
}
}  // namespace std
#endif

#if !defined(__NDK_MAJOR__) || __NDK_MAJOR__ < 23
namespace std {
inline from_chars_result from_chars(const char* first, const char* last,
                                    float& value, chars_format) noexcept {
  if (first == nullptr || last == nullptr || first >= last)
    return {first, errc::invalid_argument};
  const std::string text(first, last);
  char* end = nullptr;
  errno = 0;
  const float parsed = strtof(text.c_str(), &end);
  const std::size_t used = end == nullptr ? 0 : static_cast<std::size_t>(end - text.c_str());
  if (used == 0) return {first, errc::invalid_argument};
  // bionic strtof sets ERANGE for representable subnormals; only true
  // overflow or underflow-to-zero is an out-of-range parse here.
  if (errno == ERANGE && (parsed == 0.0f || isinf(parsed)))
    return {first + used, errc::result_out_of_range};
  value = parsed;
  return {first + used, errc{}};
}
inline from_chars_result from_chars(const char* first, const char* last,
                                    double& value, chars_format) noexcept {
  if (first == nullptr || last == nullptr || first >= last)
    return {first, errc::invalid_argument};
  const std::string text(first, last);
  char* end = nullptr;
  errno = 0;
  const double parsed = strtod(text.c_str(), &end);
  const std::size_t used = end == nullptr ? 0 : static_cast<std::size_t>(end - text.c_str());
  if (used == 0) return {first, errc::invalid_argument};
  if (errno == ERANGE && (parsed == 0.0 || isinf(parsed)))
    return {first + used, errc::result_out_of_range};
  value = parsed;
  return {first + used, errc{}};
}
}  // namespace std
#endif
