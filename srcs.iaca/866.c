#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * reference, int w, const uint8_t * filtered,
    const uint8_t * source, int thr2, int thr1, uint8_t * dst)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      const int diff = filtered[x] - source[x];
      const int diff_ref =
	((filtered[x] - reference[x]) >=
	 0 ? (filtered[x] - reference[x]) : (-(filtered[x] - reference[x])));
      if (diff_ref <= thr1)
	dst[x] = filtered[x];
      else if (diff_ref >= thr2)
	dst[x] = source[x];
      else
	dst[x] =
	  av_clip_uint8_c (source[x] +
			   diff * (thr2 - diff_ref) / (thr2 - thr1));
     } IACA_END
}
