#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef int32_t dwtcoef;
typedef __uint64_t uint64_t;

int
fn (const int right, const int q_s, const uint64_t q_m, int x,
    const uint64_t q_a, PutBitContext * pb, dwtcoef * coeff, const int left)
{
  for (x = left; x < right; x++)
     { IACA_START
      uint32_t c_abs =
	(((q_m) * (((coeff[x]) >= 0 ? (coeff[x]) : (-(coeff[x])))) +
	  (q_a)) >> (q_s));
      put_vc2_ue_uint (pb, c_abs);
      if (c_abs)
	put_bits (pb, 1, coeff[x] < 0);
     } IACA_END
}
