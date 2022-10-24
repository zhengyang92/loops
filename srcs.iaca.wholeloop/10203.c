#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;

int
fn (const I32 iWidth, U8 * piDstPixel, const float *piSrcPixel, I32 x)
{
  IACA_START for (x = 0; x < iWidth; x++)
    {
      const float r = piSrcPixel[4 * x];
      const float g = piSrcPixel[4 * x + 1];
      const float b = piSrcPixel[4 * x + 2];
      piDstPixel[3 * x] = Convert_Float_To_U8 (r);
      piDstPixel[3 * x + 1] = Convert_Float_To_U8 (g);
      piDstPixel[3 * x + 2] = Convert_Float_To_U8 (b);
}IACA_END}
