#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int scale, int i, unsigned int dc, int h, uint16_t * dst,
    const uint16_t * src, int stride)
{
  IACA_START for (i = 0; i < h; i++)
    {
      dst[0] = scale * src[0] + dc;
      if (scale)
	src += stride;
      dst += stride;
     } IACA_END
}
