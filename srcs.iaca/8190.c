#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int count, int *bounding_values, ptrdiff_t stride, unsigned char *end,
    int filter_value, uint8_t * first_pixel, const ptrdiff_t nstride)
{
  for (end = first_pixel + count; first_pixel < end; first_pixel++)
     { IACA_START
      filter_value =
	(first_pixel[2 * nstride] - first_pixel[stride]) + (first_pixel[0] -
							    first_pixel
							    [nstride]) * 3;
      filter_value = bounding_values[(filter_value + 4) >> 3];
      first_pixel[nstride] =
	av_clip_uint8_c (first_pixel[nstride] + filter_value);
      first_pixel[0] = av_clip_uint8_c (first_pixel[0] - filter_value);
     } IACA_END
}
