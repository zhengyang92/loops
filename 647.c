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
	top[j] +
	(((1.f *
	   (2 - cosf (top[j] * 3.14159265358979323846 / 1.f) -
	    cosf (bottom[j] * 3.14159265358979323846 / 1.f)) * 0.25f)) -
	 top[j]) * opacity;
}}
