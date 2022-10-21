#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (uint8_t * const pixels, int block_ptr, int pixel_x, GetByteContext * gb)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
     { IACA_START
      pixels[block_ptr++] = bytestream2_get_byte (gb);
     } IACA_END
}
