#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t * bottom, ptrdiff_t width, const float opacity,
    const uint16_t * top, uint16_t * dst)
{
  IACA_START for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	((((int)
	   av_clip_uintp2_c ((bottom[j] <
			      (1 << (14 - 1))) ? bottom[j] + 2 * top[j] -
			     ((1 << 14) - 1) : bottom[j] + 2 * (top[j] -
								(1 <<
								 (14 - 1))),
			     14))) - top[j]) * opacity;
}IACA_END}
