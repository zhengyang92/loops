#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, int step, int A, uint8_t * bsrc)
{
  IACA_START for (i = step; i < width * step; i += step)
    {
      bsrc[i] += A;
      A = bsrc[i];
     } IACA_END
}
