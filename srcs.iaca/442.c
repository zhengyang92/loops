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
	((top[j] == 0
	  && bottom[j] ==
	  0 ? 0 : 2LL * top[j] * bottom[j] / (top[j] + bottom[j])) -
	 top[j]) * opacity;
} IACA_END }
