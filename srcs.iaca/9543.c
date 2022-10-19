#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char *pixels, int block_ptr, int pixel_x, int pixel)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr++] = pixel;
    }
}
