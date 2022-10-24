#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (const uint16_t * bottom, ptrdiff_t width, const float opacity,
    const uint16_t * top, uint16_t * dst)
{
  IACA_START for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	((((int)
	   av_clip_uintp2_c (bottom[j] ==
			     0 ? ((1 << 9) - 1) : ((1 << 9) -
						   1) * top[j] / bottom[j],
			     9))) - top[j]) * opacity;
}IACA_END}
