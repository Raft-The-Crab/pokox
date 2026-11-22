#pragma once
#include <bit>
#include <cfloat>
#include <cstdint>
#include <cmath>
#include <limits>
#if defined(__FAST_MATH__)
#error "Mute deterministic math must not use fast math"
#endif
static_assert(sizeof(double)==8 && std::numeric_limits<double>::is_iec559);
static_assert(FLT_EVAL_METHOD==0, "Mute math requires binary64 intermediate precision");
#define GET_HIGH_WORD(hi,d) ((hi)=static_cast<std::uint32_t>(std::bit_cast<std::uint64_t>(d)>>32))
#define predict_false(x) (x)
#define FORCE_EVAL(x) do { volatile double poko_forced=(x); (void)poko_forced; } while(0)
namespace poko::mute::musl_math {
double sine(double); double cosine(double);
double kernel_sin(double,double,int); double kernel_cos(double,double);
int rem_pio2(double,double*); int rem_pio2_large(double*,double*,int,int,int);
double floor_value(double); double scalbn_value(double,int);
}
