#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int palette_scale, int i, unsigned char r, unsigned char g,
    uint32_t palette[256], unsigned char b, unsigned char palette_buffer[768])
{
  IACA_START for (i = 0; i < 256; i++)
    {
      r = palette_buffer[i * 3] << palette_scale;
      g = palette_buffer[i * 3 + 1] << palette_scale;
      b = palette_buffer[i * 3 + 2] << palette_scale;
      palette[i] = (0xFFU << 24) | (r << 16) | (g << 8) | (b);
      if (palette_scale == 2)
	palette[i] |= palette[i] >> 6 & 0x30303;
     } IACA_END
}
