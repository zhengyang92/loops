#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (const float *bottom, float *dst, ptrdiff_t width, const float opacity,
    const float *top)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] + ((((1) * (((top[j]) * (bottom[j])) / 1.0))) -
		  top[j]) * opacity;
}}
