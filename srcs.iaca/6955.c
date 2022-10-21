#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, int width, int step, int B, int C, const ptrdiff_t stride2, int A,
    uint8_t * bsrc)
{
  for (i = 0; i < width * step; i += step)
     { IACA_START
      B = bsrc[i - stride2];
      bsrc[i] += mid_pred (A, B, (uint8_t) (A + B - C));
      C = B;
      A = bsrc[i];
     } IACA_END
}
