#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int16_t * sample[3], int x, uint8_t * src, int stride)
{
  for (x = 0; x < w; x++)
     { IACA_START
      sample[0][x] = ((uint16_t *) (src + stride * y))[x];
     } IACA_END
}
