#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int pixel, uint8_t * const pixels, int block_ptr, int pixel_x)
{
  IACA_START for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr++] = pixel;
     } IACA_END
}
