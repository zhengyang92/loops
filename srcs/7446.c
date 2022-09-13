#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t * bottom, ptrdiff_t width, const float opacity,
    const uint16_t * top, uint16_t * dst)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	((((int)
	   av_clip_uintp2_c (top[j] * top[j] / ((1 << 10) - 1) +
			     (2 *
			      (bottom[j] *
			       ((top[j] * (((1 << 10) - 1) - top[j])) /
				((1 << 10) - 1)) / ((1 << 10) - 1))),
			     10))) - top[j]) * opacity;
}}
