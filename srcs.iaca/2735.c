#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int w, int off, uint8_t * src)
{
  for (x = off; x < w; x += 3)
     { IACA_START
      int g = src[x + 0] - ((src[x + 2] + src[x + 1]) >> 2) + 64;
      src[x + 0] = src[x + 2] + g + 128;
      src[x + 2] = src[x + 1] + g + 128;
      src[x + 1] = g;
} IACA_END }
