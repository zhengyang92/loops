#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char palette_idx2, unsigned char palette_idx1,
    int pixel_countdown, int pixel_ptr, int byte_run, unsigned char *pixels,
    int j)
{
  for (j = 0; j < byte_run; j++, pixel_countdown -= 2)
     { IACA_START
      pixels[pixel_ptr++] = palette_idx1;
      pixels[pixel_ptr++] = palette_idx2;
     } IACA_END
}
