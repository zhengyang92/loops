#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (int w, int i, int p, int be, int bpp, uint8_t * dst, GetByteContext * gb)
{
  for (i = 0; i < w; i++)
    {
      p = vmnc_get_pixel (gb, bpp, be);
      switch (bpp)
	{
	case 1:
	  dst[i] = p;
	  break;
	case 2:
	  ((uint16_t *) dst)[i] = p;
	  break;
	case 4:
	  ((uint32_t *) dst)[i] = p;
	  break;
	}
    }
}
