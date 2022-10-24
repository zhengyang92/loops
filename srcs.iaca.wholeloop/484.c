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
	((lrintf
	  (((1 << 9) - 1) * (2 -
			     cosf (top[j] * 3.14159265358979323846 /
				   ((1 << 9) - 1)) -
			     cosf (bottom[j] * 3.14159265358979323846 /
				   ((1 << 9) - 1))) * 0.25f)) -
	 top[j]) * opacity;
}IACA_END}