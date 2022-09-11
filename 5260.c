#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (uint8_t * const pixels, int pixel_x, int block_ptr, GetByteContext * gb)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr++] = bytestream2_get_byte (gb);
    }
}
