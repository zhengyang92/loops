#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int srclinesize, int x, int outw, uint8_t * dst, uint8_t * src)
{
  for (x = 0; x < outw; x++)
    {
      int32_t v =
	((((const uint8_t *) (src + x * srclinesize +
			      y * 3))[0] << 16) | (((const uint8_t *) (src +
								       x *
								       srclinesize
								       +
								       y *
								       3))[1]
						   << 8) | ((const uint8_t
							     *) (src +
								 x *
								 srclinesize +
								 y * 3))[2]);
      do
	{
	  ((uint8_t *) (dst + 3 * x))[2] = (v);
	  ((uint8_t *) (dst + 3 * x))[1] = (v) >> 8;
	  ((uint8_t *) (dst + 3 * x))[0] = (v) >> 16;
	}
      while (0);
    }
}
