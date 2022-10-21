#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int V, const uint16_t * src2, const uint16_t * src1, int k, int stride)
{
  for (; k <= 8; ++k)
     { IACA_START
      src1 += stride;
      src2 -= stride;
      V += k * (src1[0] - src2[0]);
     } IACA_END
}
