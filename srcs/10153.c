#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef unsigned char U8;
typedef int PixelI;

int
fn (PixelI * pY, const size_t cShift, const U8 * pSrc, size_t iPos,
    size_t iColumn, const size_t cColumn, size_t iRow, PixelI * pV,
    const size_t cPixelStride, const U8 idxCC[16][16], PixelI * pU)
{
  for (iColumn = 0; iColumn < cColumn; iColumn++, pSrc += cPixelStride)
    {
      PixelI iExp = (PixelI) pSrc[3];
      PixelI r = forwardRGBE (pSrc[0], iExp) << cShift;
      PixelI g = forwardRGBE (pSrc[1], iExp) << cShift;
      PixelI b = forwardRGBE (pSrc[2], iExp) << cShift;
      (b -= r, r += ((b + 1) >> 1) - g, g += ((r + 0) >> 1));
      iPos = ((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf];
      pU[iPos] = -r, pV[iPos] = b, pY[iPos] = g;
    }
}
