#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (const uint16_t * bottom, ptrdiff_t width, const float opacity,
    const uint16_t * top, uint16_t * dst)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	((((int)
	   av_clip_uintp2_c ((top[j] > bottom[j]) ? (bottom[j] ==
						     ((1 << 10) -
						      1)) ? 0 : (top[j] -
								 bottom[j]) *
			     ((1 << 10) - 1) / (((1 << 10) - 1) -
						bottom[j]) : (bottom[j] ==
							      0) ? 0
			     : (bottom[j] - top[j]) * ((1 << 10) -
						       1) / bottom[j],
			     10))) - top[j]) * opacity;
}}
