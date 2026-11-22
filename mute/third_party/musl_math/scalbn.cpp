#include "math_internal.hpp"

namespace poko::mute::musl_math {

double scalbn_value(double x, int n)
{
	uint64_t bits;
	double_t y = x;

	if (n > 1023) {
		y *= 0x1p1023;
		n -= 1023;
		if (n > 1023) {
			y *= 0x1p1023;
			n -= 1023;
			if (n > 1023)
				n = 1023;
		}
	} else if (n < -1022) {
		/* make sure final n < -53 to avoid double
		   rounding in the subnormal range */
		y *= 0x1p-1022 * 0x1p53;
		n += 1022 - 53;
		if (n < -1022) {
			y *= 0x1p-1022 * 0x1p53;
			n += 1022 - 53;
			if (n < -1022)
				n = -1022;
		}
	}
	bits = (uint64_t)(0x3ff+n)<<52;
	x = y * std::bit_cast<double>(bits);
	return x;
}

} // namespace poko::mute::musl_math
