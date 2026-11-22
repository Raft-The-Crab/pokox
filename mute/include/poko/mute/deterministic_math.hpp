#pragma once
#include <variant>
namespace poko::mute {
enum class MathError { unsupported_environment };
using MathResult = std::variant<double, MathError>;
// Portable binary64 sine/cosine. NaN and infinity produce canonical quiet NaN.
// The caller's rounding mode must be nearest-even, with gradual subnormals.
// Does not change the floating-point environment; exception flags may change.
[[nodiscard]] MathResult deterministic_sin(double x);
[[nodiscard]] MathResult deterministic_cos(double x);
} // namespace poko::mute
