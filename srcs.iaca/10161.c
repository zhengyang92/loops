#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef unsigned char U8;
typedef int PixelI;
typedef signed char I8;

int
fn (PixelI * pY, const size_t cShift, const float *pSrc, size_t iPos,
    size_t iColumn, const I8 nExpBias, const size_t cColumn, size_t iRow,
    PixelI * pV, const size_t cStride, const U8 nLen, const U8 idxCC[16][16],
    PixelI * pU)
{
  for (iColumn = 0; iColumn < cColumn; iColumn++, pSrc += cStride)
     { IACA_START
      PixelI r = float2pixel (pSrc[0], nExpBias, nLen) << cShift;
      PixelI g = float2pixel (pSrc[1], nExpBias, nLen) << cShift;
      PixelI b = float2pixel (pSrc[2], nExpBias, nLen) << cShift;
      (b -= r, r += ((b + 1) >> 1) - g, g += ((r + 0) >> 1));
      iPos = ((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf];
      pU[iPos] = -r, pV[iPos] = b, pY[iPos] = g;
     } IACA_END
}
