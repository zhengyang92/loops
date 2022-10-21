#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * bgr, int width, int YUV_HALF, uint8_t * y)
{
  for (i = 0; i < width; ++i, bgr += 3)
     { IACA_START
      y[i] = VP8RGBToY (bgr[2], bgr[1], bgr[0], YUV_HALF);
     } IACA_END
}
