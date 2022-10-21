#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char U8;
typedef int I32;

int
fn (const I32 iWidth, U8 * piDstPixel, const U8 * piSrcPixel, I32 x)
{
  for (x = 0; x < iWidth; x++)
     { IACA_START
      piDstPixel[3 * x] = piSrcPixel[4 * x];
      piDstPixel[3 * x + 1] = piSrcPixel[4 * x + 1];
      piDstPixel[3 * x + 2] = piSrcPixel[4 * x + 2];
     } IACA_END
}
