#include "poko/mute/deterministic_math.hpp"
#include "../third_party/musl_math/math_internal.hpp"
#include <bit>
#include <cfenv>
#include <cstdint>
#include <limits>
namespace poko::mute {
namespace {
bool supported() {
  if (std::fegetround()!=FE_TONEAREST) return false;
  // Check both input and result subnormal handling; reject FTZ/DAZ modes.
  volatile double smallest=std::numeric_limits<double>::denorm_min();
  volatile double one=1.0, normal=std::numeric_limits<double>::min(), half=0.5;
  const double input_check=smallest*one, output_check=normal*half;
  return std::bit_cast<std::uint64_t>(input_check)==UINT64_C(0x0000000000000001) &&
         std::bit_cast<std::uint64_t>(output_check)==UINT64_C(0x0008000000000000);
}
MathResult calculate(double x,bool sine) {
  if (!supported()) return MathError::unsupported_environment;
  const auto bits=std::bit_cast<std::uint64_t>(x);
  if ((bits&UINT64_C(0x7ff0000000000000))==UINT64_C(0x7ff0000000000000))
    return std::bit_cast<double>(UINT64_C(0x7ff8000000000000));
  return sine?musl_math::sine(x):musl_math::cosine(x);
}
}
MathResult deterministic_sin(double x) {return calculate(x,true);}
MathResult deterministic_cos(double x) {return calculate(x,false);}
} // namespace poko::mute
