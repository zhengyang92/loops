#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int in_linesize, const double *src, const uint8_t thresh,
    const int width, double *dst, int c, int r, int jobnr,
    const uint8_t * img_data)
{
  for (c = 0; c < width; ++c)
    {
      dst[jobnr] =
	((dst[jobnr]) >
	 (fabs (src[((r) * (width) + (c))]) *
	  (img_data[((r) * (in_linesize) + (c))] <
	   thresh)) ? (dst[jobnr]) : (fabs (src[((r) * (width) + (c))]) *
				      (img_data[((r) * (in_linesize) + (c))] <
				       thresh)));
    }
}
