#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;

int
fn (int w, PutBitContext p, int i, int v, int width, const uint8_t * buf,
    const uint8_t * ptr, int pix_fmt, int linesize, int AV_PIX_FMT_RGB24,
    int left)
{
  for (i = (left < 100) ? left : 100; i; i--)
    {
      if (pix_fmt == AV_PIX_FMT_RGB24)
	{
	  v = gif_clut_index (ptr[0], ptr[1], ptr[2]);
	  ptr += 3;
	}
      else
	{
	  v = *ptr++;
	}
      put_bits (&p, 9, v);
      if (--w == 0)
	{
	  w = width;
	  buf += linesize;
	  ptr = buf;
	}
    }
}
