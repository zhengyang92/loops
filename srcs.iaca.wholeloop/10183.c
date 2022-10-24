#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;

int
fn (const I32 iWidth, U8 * piDstPixel, const U8 * piSrcPixel, I32 x)
{
  IACA_START for (x = iWidth - 1; x >= 0; x--)
    {
      piDstPixel[4 * x] = piSrcPixel[3 * x];
      piDstPixel[4 * x + 1] = piSrcPixel[3 * x + 1];
      piDstPixel[4 * x + 2] = piSrcPixel[3 * x + 2];
      piDstPixel[4 * x + 3] = 0;
     } IACA_END
}
