#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *bptr, int x, const uint8_t * src, const int width)
{
  IACA_START for (x = 0; x < width; x++)
    {
      bptr[x] = src[x];
     } IACA_END
}
