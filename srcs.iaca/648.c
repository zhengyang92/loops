#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (const float *bottom, float *dst, ptrdiff_t width, const float opacity,
    const float *top)
{
  for (int j = 0; j < width; j++)
     { IACA_START
      dst[j] =
	top[j] +
	((top[j] ==
	  1.f ? 1.f : ((1.f) >
		       (1.f * bottom[j] / (2 * 1.f - 2 * top[j]) *
			(top[j] >
			 0.5f) + 2 * top[j] * bottom[j] / 1.f * (top[j] <=
								 0.5f)) ? (1.f
									   *
									   bottom
									   [j]
									   /
									   (2
									    *
									    1.f
									    -
									    2
									    *
									    top
									    [j])
									   *
									   (top
									    [j]
									    >
									    0.5f)
									   +
									   2 *
									   top
									   [j]
									   *
									   bottom
									   [j]
									   /
									   1.f
									   *
									   (top
									    [j]
									    <=
									    0.5f))
		       : (1.f))) - top[j]) * opacity;
} IACA_END }
