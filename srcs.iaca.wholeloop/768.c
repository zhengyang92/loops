#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * src16, int x, const int width, float *bptr)
{
  IACA_START for (x = 0; x < width; x++)
    {
      bptr[x] = src16[x];
     } IACA_END
}