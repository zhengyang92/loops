#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t width, const float opacity, const uint8_t * top, uint8_t * dst,
    const uint8_t * bottom)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	(((av_clip_uint8_c
	   ((top[j] - 128) * bottom[j] / (0.125f * (1 << 8)) + 128))) -
	 top[j]) * opacity;
}}
