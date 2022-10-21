#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * xf0, const uint8_t * xf1, const int width, const int z,
    uint8_t * dst)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      const int zx = z + x;
      const int zz = zx % width + width * (zx < 0);
      dst[x] = (zx > 0) && (zx < width) ? xf1[zz] : xf0[zz];
} IACA_END }
