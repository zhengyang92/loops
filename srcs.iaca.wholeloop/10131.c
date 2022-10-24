#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef int PixelI;
typedef signed char I8;
typedef unsigned char U8;

int
fn (PixelI iBias, const U8 nLen, const I8 nExpBias, size_t iColumn,
    size_t iRow, const size_t cChannel, size_t iChannel,
    PixelI * pChannel[16], float *pDst, const U8 idxCC[16][16], size_t iShift)
{
  IACA_START for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	((pChannel[iChannel & 15]
	  [((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf]] +
	  iBias) >> iShift);
      pDst[iChannel] = pixel2float (p, nExpBias, nLen);
     } IACA_END
}
