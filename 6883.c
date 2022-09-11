#include <stdint.h>
#include <stdio.h>






int
fn (int prev_block_ptr, int pixel_x, int block_ptr, unsigned char *pixels)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr++] = pixels[prev_block_ptr++];
    }
}
