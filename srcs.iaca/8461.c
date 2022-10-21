#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (int i, const int fill_color, const uint8_t * indata, const int w,
    const uint64_t max, const int depth, const int off_y,
    const int inlinesize, const uint64_t add, const int xcenter,
    const int ycenter, const int h, uint8_t * out, const int32_t * correction)
{
  for (int j = 0; j < w; j++)
     { IACA_START
      const int off_x = j - xcenter;
      const int64_t radius_mult = correction[j + i * w];
      const int x = xcenter + ((radius_mult * off_x + (1 << 23)) >> 24);
      const int y = ycenter + ((radius_mult * off_y + (1 << 23)) >> 24);
      const char isvalid = x >= 0 && x <= w - 1 && y >= 0 && y <= h - 1;
      if (isvalid)
	{
	  const int nx = ((x + 1) > (w - 1) ? (w - 1) : (x + 1));
	  const int ny = ((y + 1) > (h - 1) ? (h - 1) : (y + 1));
	  const uint64_t du =
	    off_x >=
	    0 ? (radius_mult * off_x + add) & max : max -
	    ((radius_mult * -off_x + add) & max);
	  const uint64_t dv =
	    off_y >=
	    0 ? (radius_mult * off_y + add) & max : max -
	    ((radius_mult * -off_y + add) & max);
	  const uint64_t p0 = indata[y * inlinesize + x];
	  const uint64_t p1 = indata[y * inlinesize + nx];
	  const uint64_t p2 = indata[ny * inlinesize + x];
	  const uint64_t p3 = indata[ny * inlinesize + nx];
	  uint64_t sum = 0;
	  sum += (max - du) * (max - dv) * p0;
	  sum += (du) * (max - dv) * p1;
	  sum += (max - du) * (dv) * p2;
	  sum += (du) * (dv) * p3;
	  out[j] = av_clip_uintp2_c ((sum + (1ULL << 47)) >> 48, depth);
	}
      else
	{
	  out[j] = fill_color;
	}
     } IACA_END
}
