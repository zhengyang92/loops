#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int g, int i, int r, const uint8_t * src, int a, uint8_t * dst,
    int b)
{
  for (i = 0; i < w; i++)
    {
      b += src[4 * i + 0];
      g += src[4 * i + 1];
      r += src[4 * i + 2];
      a += src[4 * i + 3];
      dst[4 * i + 0] = b;
      dst[4 * i + 1] = g;
      dst[4 * i + 2] = r;
      dst[4 * i + 3] = a;
    }
}
