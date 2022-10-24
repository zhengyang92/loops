#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t g, int width, uint8_t * src, uint8_t r, uint8_t b,
    int step)
{
  IACA_START for (i = 0; i < width * step; i += step)
    {
      r = src[i];
      g = src[i + 1];
      b = src[i + 2];
      src[i] = r + g - 0x80;
      src[i + 2] = b + g - 0x80;
     } IACA_END
}
