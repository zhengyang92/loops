#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint64_t uint64_t;
typedef int32_t dwtcoef;

int
fn (const int q_s, const int right, const uint64_t q_m, int x,
    const uint64_t q_a, PutBitContext * pb, dwtcoef * coeff, const int left)
{
  IACA_START for (x = left; x < right; x++)
    {
      uint32_t c_abs =
	(((q_m) * (((coeff[x]) >= 0 ? (coeff[x]) : (-(coeff[x])))) +
	  (q_a)) >> (q_s));
      put_vc2_ue_uint (pb, c_abs);
      if (c_abs)
	put_bits (pb, 1, coeff[x] < 0);
     } IACA_END
}
