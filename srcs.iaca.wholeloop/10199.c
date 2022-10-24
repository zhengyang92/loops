#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned short U16;
typedef int I32;
typedef unsigned char U8;

int
fn (const I32 iWidth, U8 * piDstPixel, I32 x, const U16 * piSrcPixel)
{
  IACA_START for (x = 0; x < iWidth; x++)
    {
      const U16 r = piSrcPixel[3 * x];
      const U16 g = piSrcPixel[3 * x + 1];
      const U16 b = piSrcPixel[3 * x + 2];
      piDstPixel[3 * x] = r >> 8;
      piDstPixel[3 * x + 1] = g >> 8;
      piDstPixel[3 * x + 2] = b >> 8;
}IACA_END}
