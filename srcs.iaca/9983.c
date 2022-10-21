#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t * y, int YUV_HALF, const uint8_t * rgb)
{
  for (i = 0; i < width; ++i, rgb += 3)
     { IACA_START
      y[i] = VP8RGBToY (rgb[0], rgb[1], rgb[2], YUV_HALF);
     } IACA_END
}
