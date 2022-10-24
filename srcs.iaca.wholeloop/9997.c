#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, const uint8_t * bgr, int YUV_HALF, uint8_t * y)
{
  IACA_START for (; i < width; ++i, bgr += 3)
    {
      y[i] = VP8RGBToY (bgr[2], bgr[1], bgr[0], YUV_HALF);
     } IACA_END
}
