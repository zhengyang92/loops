#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;

int
fn (I32 x, const I32 iWidth, const I32 * piSrcPixel, const float fltCvtFactor,
    U8 * pfltDstPixel)
{
  IACA_START for (x = 0; x < iWidth; x++)
    {
      pfltDstPixel[3 * x] =
	Convert_Float_To_U8 (piSrcPixel[4 * x] * fltCvtFactor);
      pfltDstPixel[3 * x + 1] =
	Convert_Float_To_U8 (piSrcPixel[4 * x + 1] * fltCvtFactor);
      pfltDstPixel[3 * x + 2] =
	Convert_Float_To_U8 (piSrcPixel[4 * x + 2] * fltCvtFactor);
     } IACA_END
}
