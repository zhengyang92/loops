#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int y, int w, int x, uint8_t * dst, ptrdiff_t src_linesize, uint8_t * src)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int32_t v =
	((((const uint8_t *) (src + x * src_linesize +
			      y * 3))[0] << 16) | (((const uint8_t *) (src +
								       x *
								       src_linesize
								       +
								       y *
								       3))[1]
						   << 8) | ((const uint8_t
							     *) (src +
								 x *
								 src_linesize
								 +
								 y * 3))[2]);
      do
	{
	  ((uint8_t *) (dst + 3 * x))[2] = (v);
	  ((uint8_t *) (dst + 3 * x))[1] = (v) >> 8;
	  ((uint8_t *) (dst + 3 * x))[0] = (v) >> 16;
	}
      while (0);
     } IACA_END
}
