#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int scale, unsigned int dc, int i, int h, uint16_t * dst,
    const uint16_t * src, int stride)
{
  for (i = 0; i < h; i++)
    {
      dst[0] = scale * src[0] + dc;
      if (scale)
	src += stride;
      dst += stride;
    }
}
