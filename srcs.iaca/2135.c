#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * dst, int w, const uint8_t * src)
{
  for (x = 0; x < w - 7; x += 8)
    {
      dst[x + 0] = dst[x + 1] = src[(x >> 1) + 0];
      dst[x + 2] = dst[x + 3] = src[(x >> 1) + 1];
      dst[x + 4] = dst[x + 5] = src[(x >> 1) + 2];
      dst[x + 6] = dst[x + 7] = src[(x >> 1) + 3];
    }
}
