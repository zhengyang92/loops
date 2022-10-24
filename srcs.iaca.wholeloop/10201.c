#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char U8;
typedef int I32;

int
fn (const I32 iWidth, U8 * piDstPixel, const float *piSrcPixel, I32 x)
{
  IACA_START for (x = 0; x < iWidth; x++)
    {
      const float v = piSrcPixel[x];
      piDstPixel[x] = Convert_Float_To_U8 (v);
}IACA_END}
