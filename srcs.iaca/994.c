#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int height, const float shy, int y, const float wy, const int hsub,
    const float shx, const int depth, const int width, const float wx,
    const int vsub, const uint8_t * src, const int src_linesize,
    uint8_t * dst)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      const float sx = x + vsub * shx * y / hsub - wx;
      const float sy = y + hsub * shy * x / vsub - wy;
      if (sx >= 0 && sx < width - 1 && sy >= 0 && sy < height - 1)
	{
	  float sum = 0.f;
	  int ax = floorf (sx);
	  int ay = floorf (sy);
	  float du = sx - ax;
	  float dv = sy - ay;
	  int bx = ((ax + 1) > (width - 1) ? (width - 1) : (ax + 1));
	  int by = ((ay + 1) > (height - 1) ? (height - 1) : (ay + 1));
	  sum += (1.f - du) * (1.f - dv) * src[ay * src_linesize + ax];
	  sum += (du) * (1.f - dv) * src[ay * src_linesize + bx];
	  sum += (1.f - du) * (dv) * src[by * src_linesize + ax];
	  sum += (du) * (dv) * src[by * src_linesize + bx];
	  dst[x] = av_clip_uintp2_c (lrintf (sum), depth);
	}
} IACA_END }
