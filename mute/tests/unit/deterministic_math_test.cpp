#include "poko/mute/deterministic_math.hpp"
#include <bit>
#include <cfenv>
#include <cstdint>
#include <iostream>
#include <limits>
#include <variant>
#if defined(__SSE__)
#include <xmmintrin.h>
#endif
using namespace poko::mute;
int main() {
  int errors=0;
  auto test=[&](double x,bool sine,std::uint64_t expected) {
    auto value=sine?deterministic_sin(x):deterministic_cos(x);
    if (!std::holds_alternative<double>(value) || std::bit_cast<std::uint64_t>(std::get<double>(value))!=expected) {++errors;std::cerr<<"unexpected math value\n";}
  };
  test(0.0,true,UINT64_C(0));test(-0.0,true,UINT64_C(0x8000000000000000));
  test(0.0,false,UINT64_C(0x3ff0000000000000));
  test(std::numeric_limits<double>::denorm_min(),true,UINT64_C(1));
  test(std::numeric_limits<double>::infinity(),true,UINT64_C(0x7ff8000000000000));
  test(-std::numeric_limits<double>::infinity(),false,UINT64_C(0x7ff8000000000000));
  test(std::bit_cast<double>(UINT64_C(0xfff8000000000042)),true,UINT64_C(0x7ff8000000000000));
#if defined(__SSE__)
  const auto original_mxcsr=_mm_getcsr();
  _mm_setcsr(original_mxcsr | 0x8040U); // FTZ + DAZ
  if (!std::holds_alternative<MathError>(deterministic_sin(1.0))) {std::cerr<<"FTZ/DAZ not rejected\n";++errors;}
  _mm_setcsr(original_mxcsr);
#endif
  const auto old=std::fegetround();
  if (old==-1 || std::fesetround(FE_DOWNWARD)!=0) { std::cerr<<"cannot set rounding mode\n";return 1; }
  if (!std::holds_alternative<MathError>(deterministic_sin(1.0)) || !std::holds_alternative<MathError>(deterministic_cos(1.0))) {std::cerr<<"rounding mode not rejected\n";++errors;}
  if (std::fegetround()!=FE_DOWNWARD || std::fesetround(old)!=0) {std::cerr<<"rounding mode was modified\n";++errors;}
  return errors?1:0;
}
