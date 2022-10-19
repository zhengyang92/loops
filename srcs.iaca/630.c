#include "../iacaMarks.h"
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
	(((((top[j]) <= 0.0) ? (top[j]) : ((0.0) >
					   (1.0 -
					    (1.0 -
					     (bottom[j])) /
					    (top[j])) ? (0.0) : (1.0 - (1.0 -
									(bottom
									 [j]))
								 /
								 (top[j])))))
	 - top[j]) * opacity;
}}
