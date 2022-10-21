#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int height, const float shy, int y, const int hsub, const float shx,
    const int wx, const int width, const int vsub, const int wy,
    const int src_linesize, uint16_t * dst, const uint16_t * src)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      int sx = x + vsub * shx * y / hsub - wx;
      int sy = y + hsub * shy * x / vsub - wy;
      if (sx >= 0 && sx < width - 1 && sy >= 0 && sy < height - 1)
	{
	  dst[x] = src[sy * src_linesize + sx];
	}
     } IACA_END
}
