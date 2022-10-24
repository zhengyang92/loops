#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int width, int B, int C, const ptrdiff_t stride2, int A,
    uint8_t * bsrc)
{
  IACA_START for (i = 1; i < width; i++)
    {
      A = bsrc[i - stride2];
      B = bsrc[i - (stride2 + 1)];
      C = bsrc[i - 1];
      bsrc[i] = (A - B + C + bsrc[i]) & 0xFF;
     } IACA_END
}
