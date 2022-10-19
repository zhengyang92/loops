#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int width, int B, int C, int A, uint8_t * bsrc)
{
  for (i = 1; i < width; i++)
    {
      A = bsrc[i - stride];
      B = bsrc[i - (1 + stride)];
      C = bsrc[i - 1 + stride];
      bsrc[i + stride] = (A - B + C + bsrc[i + stride]) & 0xFF;
    }
}
