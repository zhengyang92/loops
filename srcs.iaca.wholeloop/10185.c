#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef short I16;

int
fn (I32 x, const I32 iWidth, float *pfltDstPixel, const float fltCvtFactor,
    const I16 * piSrcPixel)
{
  IACA_START for (x = iWidth - 1; x >= 0; x--)
    {
      pfltDstPixel[3 * x] = piSrcPixel[4 * x] * fltCvtFactor;
      pfltDstPixel[3 * x + 1] = piSrcPixel[4 * x + 1] * fltCvtFactor;
      pfltDstPixel[3 * x + 2] = piSrcPixel[4 * x + 2] * fltCvtFactor;
     } IACA_END
}
