#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;

int
fn (I32 x, const I32 iWidth, const I32 * piSrcPixel, const float fltCvtFactor,
    U8 * piDstPixel)
{
  for (x = 0; x < iWidth; x++)
    {
      piDstPixel[x] = Convert_Float_To_U8 (piSrcPixel[x] * fltCvtFactor);
    }
}
