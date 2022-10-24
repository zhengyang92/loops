#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int stride, unsigned int dc, int i, int h, uint16_t * src, uint16_t * dst,
    int scale)
{
  IACA_START for (i = 0; i < h; i++)
    {
      dst[0] = scale * src[0] + dc;
      if (scale)
	src += stride;
      dst += stride;
     } IACA_END
}
