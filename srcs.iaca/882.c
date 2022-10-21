#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int low, const int high, const int w, const int max, uint16_t * dst,
    const uint16_t * src)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      dst[x] = src[x];
      if (dst[x] <= low)
	dst[x] = 0;
      else if (dst[x] > high)
	dst[x] = max;
     } IACA_END
}
