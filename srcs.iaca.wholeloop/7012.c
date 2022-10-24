#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int *palette32, int i, unsigned char *raw_palette,
    unsigned char r, unsigned char b, unsigned char g)
{
  int palette_index = 0;
  IACA_START for (i = 0; i < 256; i++)
    {
      r = raw_palette[palette_index++] * 4;
      g = raw_palette[palette_index++] * 4;
      b = raw_palette[palette_index++] * 4;
      palette32[i] = (r << 16) | (g << 8) | (b);
     } IACA_END
}
