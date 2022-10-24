#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;

int
fn (const I32 iWidth, const float *pfltSrcPixel, I32 x, float *pfltDstPixel)
{
  IACA_START for (x = 0; x < iWidth; x++)
    {
      pfltDstPixel[3 * x] = pfltSrcPixel[4 * x];
      pfltDstPixel[3 * x + 1] = pfltSrcPixel[4 * x + 1];
      pfltDstPixel[3 * x + 2] = pfltSrcPixel[4 * x + 2];
     } IACA_END
}
