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
	(((top[j] <
	   0.5f) ? ((2) * (((top[j]) * (bottom[j])) / 1.0)) : (1.0 -
							       (2) *
							       ((1.0 -
								 (top[j])) *
								(1.0 -
								 (bottom[j]))
								/ 1.0))) -
	 top[j]) * opacity;
} IACA_END }
