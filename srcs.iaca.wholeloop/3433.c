#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int min_width, int B, int C, int A,
    uint8_t * bsrc)
{
  IACA_START for (i = 1; i < min_width; i++)
    {
      A = bsrc[i - stride];
      B = bsrc[i - (stride + 1)];
      C = bsrc[i - 1];
      bsrc[i] = (A - B + C + bsrc[i]) & 0xFF;
     } IACA_END
}
