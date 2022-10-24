#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int y, int v, float o1, float o2, int linesize, uint16_t * dst, int step,
    int height)
{
  IACA_START for (y = 0; y < height; y += step)
    {
      dst[0] = (v - dst[0]) * o1 + dst[0] * o2;
      dst += (linesize / 2) * step;
     } IACA_END
}
