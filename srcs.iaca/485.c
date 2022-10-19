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
    {
      dst[j] =
	top[j] +
	((top[j] ==
	  ((1 << 9) - 1) ? ((1 << 9) - 1) : ((((1 << 9) - 1)) >
					     (((1 << 9) -
					       1) * bottom[j] / (2 *
								 ((1 << 9) -
								  1) -
								 2 * top[j]) *
					      (top[j] >
					       (1 << (9 - 1))) +
					      2 * top[j] * bottom[j] /
					      ((1 << 9) - 1) * (top[j] <=
								(1 <<
								 (9 -
								  1)))) ? (((1
									     <<
									     9)
									    -
									    1)
									   *
									   bottom
									   [j]
									   /
									   (2
									    *
									    ((1 << 9) - 1) - 2 * top[j]) * (top[j] > (1 << (9 - 1))) + 2 * top[j] * bottom[j] / ((1 << 9) - 1) * (top[j] <= (1 << (9 - 1)))) : (((1 << 9) - 1)))) - top[j]) * opacity;
}}
