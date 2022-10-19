#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int width, uint8_t * bsrc, int A, int step)
{
  for (i = 0; i < width * step; i += step)
    {
      bsrc[stride + i] += A;
      A = bsrc[stride + i];
    }
}
