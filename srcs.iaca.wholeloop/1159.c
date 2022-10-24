#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int v, int x, int width, float o1, float o2, uint16_t * dst, int step)
{
  IACA_START for (x = 0; x < width; x += step)
    {
      dst[x] = (v - dst[x]) * o1 + dst[x] * o2;
     } IACA_END
}
