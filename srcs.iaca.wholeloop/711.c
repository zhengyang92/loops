#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int height, int g, const double *src, const int width, int r, int c,
    const double *gauss, const int filtersize, double *dst)
{
  IACA_START for (g = 0; g < filtersize; ++g)
    {
      dst[((r) * (width) + (c))] +=
	((src)
	 [((av_clip_c
	    (((r + ((g) - ((filtersize) >> 2)))), 0,
	     ((height) - 1))) * ((width)) + (av_clip_c (((c)), 0,
							((width) -
							 1))))] * (gauss[g]));
     } IACA_END
}
