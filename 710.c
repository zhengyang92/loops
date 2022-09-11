#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int height, const int in_linesize, int g, const int width, int r,
    int c, const uint8_t * src, const double *gauss, const int filtersize,
    double *dst)
{
  for (g = 0; g < filtersize; ++g)
    {
      dst[((r) * (width) + (c))] +=
	((src)
	 [((av_clip_c (((r)), 0, ((height) - 1))) * ((in_linesize)) +
	   (av_clip_c
	    (((c + ((g) - ((filtersize) >> 2)))), 0,
	     ((width) - 1))))] * (gauss[g]));
    }
}
