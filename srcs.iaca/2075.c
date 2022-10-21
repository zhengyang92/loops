#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int pixel_countdown, int pixel_ptr, int pixel, int byte_run,
    unsigned char *pixels, int j)
{
  for (j = 0; j < byte_run; j++, pixel_countdown -= 2)
     { IACA_START
      *((signed short *) (&pixels[pixel_ptr])) = pixel;
      pixel_ptr += 2;
} IACA_END }
