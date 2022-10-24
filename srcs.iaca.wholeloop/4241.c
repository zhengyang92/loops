#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t width, const float opacity, const uint8_t * top, uint8_t * dst,
    const uint8_t * bottom)
{
  IACA_START for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	(((av_clip_uint8_c
	   ((top[j] > bottom[j]) ? (bottom[j] ==
				    255) ? 0 : (top[j] -
						bottom[j]) * 255 / (255 -
								    bottom[j])
	    : (bottom[j] ==
	       0) ? 0 : (bottom[j] - top[j]) * 255 / bottom[j]))) -
	 top[j]) * opacity;
}IACA_END}
