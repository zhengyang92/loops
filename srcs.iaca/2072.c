#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;

int
fn (int pixel_countdown, GetByteContext g2, int pixel_ptr, int byte_run,
    unsigned char *pixels, int j)
{
  for (j = 0; j < byte_run * 2; j++, pixel_countdown--)
     { IACA_START
      pixels[pixel_ptr++] = bytestream2_get_byte (&g2);
     } IACA_END
}
