#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int width, int B, int C, uint8_t * bsrc, int A,
    int step)
{
  for (i = step; i < width * step; i += step)
    {
      A = bsrc[i - stride];
      B = bsrc[i - (step + stride)];
      C = bsrc[i - step + stride];
      bsrc[i + stride] = (A - B + C + bsrc[i + stride]) & 0xFF;
    }
}
