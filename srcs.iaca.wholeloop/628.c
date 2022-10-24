#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (const float *bottom, float *dst, ptrdiff_t width, const float opacity,
    const float *top)
{
  IACA_START for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] + (((bottom[j] == 0 ? 1.f : 1.f * top[j] / bottom[j])) -
		  top[j]) * opacity;
}IACA_END}
