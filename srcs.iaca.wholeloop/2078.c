#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;

int
fn (int pixel_countdown, int pixel_ptr, int pixel, GetByteContext g2,
    int byte_run, unsigned char *pixels, int j)
{
  IACA_START for (j = 0; j < byte_run; j++, pixel_countdown--)
    {
      pixel = bytestream2_get_le24 (&g2);
      do
	{
	  ((uint8_t *) (&pixels[pixel_ptr]))[0] = (pixel);
	  ((uint8_t *) (&pixels[pixel_ptr]))[1] = (pixel) >> 8;
	  ((uint8_t *) (&pixels[pixel_ptr]))[2] = (pixel) >> 16;
	}
      while (0);
      pixel_ptr += 3;
     } IACA_END
}
