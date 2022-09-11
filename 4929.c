#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int stride, const uint16_t * src2, const uint16_t * src1, int k, int V)
{
  for (; k <= 8; ++k)
    {
      src1 += stride;
      src2 -= stride;
      V += k * (src1[0] - src2[0]);
    }
}
