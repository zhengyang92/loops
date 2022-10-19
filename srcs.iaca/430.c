#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t width, const float opacity, const uint8_t * top, uint8_t * dst,
    const uint8_t * bottom)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] + ((top[j] + bottom[j] - 2 * top[j] * bottom[j] / 255) -
		  top[j]) * opacity;
}}
