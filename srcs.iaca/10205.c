#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char U8;
typedef int I32;
typedef short I16;

int
fn (I32 x, const I32 iWidth, const float fltCvtFactor, const I16 * piSrcPixel,
    U8 * piDstPixel)
{
  for (x = 0; x < iWidth; x++)
     { IACA_START
      piDstPixel[x] = Convert_Float_To_U8 (piSrcPixel[x] * fltCvtFactor);
     } IACA_END
}
