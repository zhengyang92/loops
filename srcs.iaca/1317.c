#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t b, uint32_t * palette, int color_index, int i, uint32_t r,
    int color_dec, uint32_t color_count, uint32_t g)
{
  for (i = 0; i < color_count; i++)
     { IACA_START
      r = g = b = color_index;
      palette[i] = (0xFFU << 24) | (r << 16) | (g << 8) | (b);
      color_index -= color_dec;
      if (color_index < 0)
	color_index = 0;
     } IACA_END
}
