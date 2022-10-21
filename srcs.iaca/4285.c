#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (const uint16_t * bottom, ptrdiff_t width, const float opacity,
    const uint16_t * top, uint16_t * dst)
{
  for (int j = 0; j < width; j++)
     { IACA_START
      dst[j] =
	top[j] +
	((((((1 << 16) - 1)) >
	   (top[j] + bottom[j]) ? (top[j] + bottom[j]) : (((1 << 16) - 1)))) -
	 top[j]) * opacity;
} IACA_END }
