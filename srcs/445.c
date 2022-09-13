#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t width, const float opacity, const uint8_t * top, uint8_t * dst,
    const uint8_t * bottom)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	((lrintf
	  (255 *
	   (2 - cosf (top[j] * 3.14159265358979323846 / 255) -
	    cosf (bottom[j] * 3.14159265358979323846 / 255)) * 0.25f)) -
	 top[j]) * opacity;
}}
