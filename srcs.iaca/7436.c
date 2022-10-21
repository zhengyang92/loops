#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t width, const float opacity, const uint8_t * top, uint8_t * dst,
    const uint8_t * bottom)
{
  for (int j = 0; j < width; j++)
     { IACA_START
      dst[j] =
	top[j] +
	(((av_clip_uint8_c
	   (top[j] * top[j] / 255 +
	    (2 * (bottom[j] * ((top[j] * (255 - top[j])) / 255) / 255))))) -
	 top[j]) * opacity;
} IACA_END }
