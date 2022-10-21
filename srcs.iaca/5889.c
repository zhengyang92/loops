#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t * palette, int i, uint8_t g, uint16_t color, int array_offset,
    uint8_t r, uint8_t b, uint8_t * data)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      color = (data[2 * i] << 6) + (data[2 * i + 1] & 0x3F);
      r = ((color >> 8) & 0x000F) * 17;
      g = ((color >> 4) & 0x000F) * 17;
      b = ((color) & 0x000F) * 17;
      palette[i + array_offset] = r << 16 | g << 8 | b;
     } IACA_END
}
