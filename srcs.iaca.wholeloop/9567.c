#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int width, int step, int B, int C, int A,
    uint8_t * bsrc)
{
  IACA_START for (i = 0; i < width * step; i += step)
    {
      B = bsrc[i - stride];
      bsrc[stride + i] += mid_pred (A, B, (uint8_t) (A + B - C));
      C = B;
      A = bsrc[stride + i];
     } IACA_END
}
