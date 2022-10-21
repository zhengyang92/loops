#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int height, int y, const uint8_t * xf0, float progress,
    const uint8_t * xf1, const int width, float z, uint8_t * dst,
    const int bg)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      float dist = hypotf (x - width / 2, y - height / 2);
      int val = progress < 0.5f ? xf1[x] : xf0[x];
      dst[x] = (z < dist) ? bg : val;
} IACA_END }
