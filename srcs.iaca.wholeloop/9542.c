#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char *pixels, int prev_block_ptr, int block_ptr, int pixel_x)
{
  IACA_START for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr++] = pixels[prev_block_ptr++];
     } IACA_END
}
