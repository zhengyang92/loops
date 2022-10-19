#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int low, const int high, const int w, const uint8_t * src,
    const int max, uint8_t * dst)
{
  for (int x = 0; x < w; x++)
    {
      dst[x] = src[x];
      if (dst[x] <= low)
	dst[x] = 0;
      else if (dst[x] > high)
	dst[x] = max;
    }
}
