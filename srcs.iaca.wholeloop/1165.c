#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int height, int y, float progress, const int width,
    const uint16_t * xf1, float z, const uint16_t * xf0, uint16_t * dst,
    const int bg)
{
  IACA_START for (int x = 0; x < width; x++)
    {
      float dist = hypotf (x - width / 2, y - height / 2);
      int val = progress < 0.5f ? xf1[x] : xf0[x];
      dst[x] = (z < dist) ? bg : val;
}IACA_END}
