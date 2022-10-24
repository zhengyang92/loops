#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t width, const float opacity, const uint8_t * top, uint8_t * dst,
    const uint8_t * bottom)
{
  IACA_START for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	((top[j] ==
	  255 ? 255 : ((255) >
		       (255 * bottom[j] / (2 * 255 - 2 * top[j]) *
			(top[j] >
			 128) + 2 * top[j] * bottom[j] / 255 * (top[j] <=
								128)) ? (255 *
									 bottom
									 [j] /
									 (2 *
									  255
									  -
									  2 *
									  top
									  [j])
									 *
									 (top
									  [j]
									  >
									  128)
									 +
									 2 *
									 top
									 [j] *
									 bottom
									 [j] /
									 255 *
									 (top
									  [j]
									  <=
									  128))
		       : (255))) - top[j]) * opacity;
}IACA_END}
