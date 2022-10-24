#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int width, int step, int B, int C, const ptrdiff_t stride2, int A,
    uint8_t * bsrc)
{
  IACA_START for (i = 0; i < width * step; i += step)
    {
      B = bsrc[i - stride2];
      bsrc[i] += mid_pred (A, B, (uint8_t) (A + B - C));
      C = B;
      A = bsrc[i];
     } IACA_END
}
