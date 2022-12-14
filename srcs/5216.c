#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t color4[4], uint16_t * pixels, int block_ptr, int pixel_x,
    uint8_t index)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      uint8_t idx = (index >> (2 * (3 - pixel_x))) & 0x03;
      pixels[block_ptr] = color4[idx];
      block_ptr++;
    }
}
