#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef short I16;

int
fn (const I32 iWidth, I32 x, I16 * piDstPixel, const short *piSrcPixel)
{
  IACA_START for (x = 0; x < iWidth; x++)
    {
      piDstPixel[3 * x] = piSrcPixel[4 * x];
      piDstPixel[3 * x + 1] = piSrcPixel[4 * x + 1];
      piDstPixel[3 * x + 2] = piSrcPixel[4 * x + 2];
     } IACA_END
}
