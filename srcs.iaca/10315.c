#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, unsigned char *tga_palette, unsigned char raw_data[4], int pal_idx,
    int tga_comp)
{
  for (j = 0; j < tga_comp; ++j)
     { IACA_START
      raw_data[j] = tga_palette[pal_idx + j];
     } IACA_END
}
