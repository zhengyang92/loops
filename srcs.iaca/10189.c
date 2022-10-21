#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef short I16;

int
fn (const I32 iWidth, const float *pfltSrcPixel, I32 x, I16 * piDstPixel)
{
  for (x = 0; x < iWidth; x++)
     { IACA_START
      piDstPixel[4 * x] = Convert_Float_To_Half (pfltSrcPixel[3 * x]);
      piDstPixel[4 * x + 1] = Convert_Float_To_Half (pfltSrcPixel[3 * x + 1]);
      piDstPixel[4 * x + 2] = Convert_Float_To_Half (pfltSrcPixel[3 * x + 2]);
      piDstPixel[4 * x + 3] = 0;
     } IACA_END
}
