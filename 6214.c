#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int V, int H, const uint8_t * src2, const uint8_t * const src0, int k,
    const uint8_t * src1, int stride)
{
  for (k = 2; k <= 4; ++k)
    {
      src1 += stride;
      src2 -= stride;
      H += k * (src0[k] - src0[-k]);
      V += k * (src1[0] - src2[0]);
    }
}
