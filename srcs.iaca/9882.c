#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int num_pixels, const uint32_t * const dst, int i, uint32_t * const src)
{
  for (i = 0; i < num_pixels; ++i)
     { IACA_START
      const uint8_t src_alpha = (src[i] >> 24) & 0xff;
      if (src_alpha != 0xff)
	{
	  src[i] = BlendPixelPremult (src[i], dst[i]);
	}
     } IACA_END
}
