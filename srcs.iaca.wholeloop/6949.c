#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int width, int B, int C, uint8_t * bsrc, int A,
    int step)
{
  IACA_START for (i = step; i < width * step; i += step)
    {
      B = bsrc[i - stride];
      bsrc[i] += mid_pred (A, B, (uint8_t) (A + B - C));
      C = B;
      A = bsrc[i];
     } IACA_END
}
