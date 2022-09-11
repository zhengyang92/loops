#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int i, int h, const uint8_t * src, int size, int src_stride,
    uint8_t * dst)
{
  for (i = 0; i < h; ++i)
    {
      memcpy (dst, src, w);
      if (w < size)
	{
	  memset (dst + w, dst[w - 1], size - w);
	}
      dst += 32;
      src += src_stride;
    }
}
