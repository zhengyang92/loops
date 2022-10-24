#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *bptr, int x, uint8_t * dst, const int width)
{
  IACA_START for (x = 0; x < width; x++)
    {
      dst[x] = bptr[x];
     } IACA_END
}
