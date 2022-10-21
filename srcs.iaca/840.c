#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *bptr, int x, uint8_t * dst, const int width)
{
  for (x = 0; x < width; x++)
     { IACA_START
      dst[x] = bptr[x];
     } IACA_END
}
