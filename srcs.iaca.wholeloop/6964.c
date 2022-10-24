#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t ** dst, int width, uint8_t * src, int k, unsigned int g,
    int step)
{
  IACA_START for (i = 0; i < width * step; i += step)
    {
      g = src[i + 1];
      dst[0][k] = g;
      g += 0x80;
      dst[1][k] = src[i + 2] - g;
      dst[2][k] = src[i + 0] - g;
      dst[3][k] = src[i + 3];
      k++;
     } IACA_END
}
