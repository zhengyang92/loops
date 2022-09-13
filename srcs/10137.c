#include <stdint.h>
#include <stdio.h>




typedef signed char I8;
typedef int PixelI;
typedef unsigned char U8;
typedef long unsigned int size_t;

int
fn (const I8 nExpBias, const size_t rShiftY, size_t iColumn, float *pDst,
    size_t iRow, const size_t cChannel, size_t iChannel,
    PixelI * pChannel[16], const PixelI cMul, const U8 nLen,
    const U8 idxCC[16][16])
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	(pChannel[iChannel & 15]
	 [((iColumn >> 4) << 8) +
	  idxCC[iRow][iColumn & 15]] * cMul) >> rShiftY;
      pDst[iChannel] = pixel2float (p, nExpBias, nLen);
    }
}
