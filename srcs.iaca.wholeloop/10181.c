#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef short I16;

int
fn (const I32 iWidth, I32 x, const I16 * piSrcPixel, I16 * piDstPixel)
{
  IACA_START for (x = iWidth - 1; x >= 0; x--)
    {
      piDstPixel[4 * x] = piSrcPixel[3 * x];
      piDstPixel[4 * x + 1] = piSrcPixel[3 * x + 1];
      piDstPixel[4 * x + 2] = piSrcPixel[3 * x + 2];
      piDstPixel[4 * x + 3] = 0;
     } IACA_END
}
