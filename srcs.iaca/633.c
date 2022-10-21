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
	(((bottom[j] < 0.5f) ? ((top[j]) >
				(2 * bottom[j]) ? (2 *
						   bottom[j]) : (top[j]))
	  : ((top[j]) >
	     (2 * (bottom[j] - 0.5f)) ? (top[j]) : (2 *
						    (bottom[j] - 0.5f)))) -
	 top[j]) * opacity;
} IACA_END }
