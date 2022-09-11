#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int pixel, uint8_t * const pixels, int pixel_x, int block_ptr)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr++] = pixel;
    }
}
