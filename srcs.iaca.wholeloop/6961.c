#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int width, int step, int B, int C, const ptrdiff_t stride2, int A,
    uint8_t * bsrc)
{
  IACA_START for (i = step; i < width * step; i += step)
    {
      A = bsrc[i - stride2];
      B = bsrc[i - (stride2 + step)];
      C = bsrc[i - step];
      bsrc[i] = (A - B + C + bsrc[i]) & 0xFF;
     } IACA_END
}
