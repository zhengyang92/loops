#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int V, int H, const uint16_t * src2, const uint16_t * src1, int k,
    const uint16_t * const src0, int stride)
{
  for (k = 2; k <= 4; ++k)
    {
      src1 += stride;
      src2 -= stride;
      H += k * (src0[k] - src0[-k]);
      V += k * (src1[0] - src2[0]);
    }
}
