#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, const uint16_t * source, const uint16_t * filtered, int thr2,
    const uint16_t * reference, int depth, int thr1, uint16_t * dst)
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
	  av_clip_uintp2_c (source[x] +
			    diff * (thr2 - diff_ref) / (thr2 - thr1), depth);
     } IACA_END
}
