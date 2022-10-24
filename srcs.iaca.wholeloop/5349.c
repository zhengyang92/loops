#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t dwtcoef;
typedef __uint64_t uint64_t;

int
fn (const int q_s, const int right, const uint64_t q_m, int bits, int x,
    const uint64_t q_a, dwtcoef * buf, const int left)
{
  IACA_START for (x = left; x < right; x++)
    {
      uint32_t c_abs =
	(((q_m) * (((buf[x]) >= 0 ? (buf[x]) : (-(buf[x])))) +
	  (q_a)) >> (q_s));
      bits += count_vc2_ue_uint (c_abs);
      bits += !!c_abs;
     } IACA_END
}
