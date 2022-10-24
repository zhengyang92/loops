#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef short I16;
typedef int PixelI;
typedef unsigned char U8;

int
fn (PixelI iBias, size_t iColumn, I16 * pDst, size_t iRow,
    const size_t cChannel, size_t iChannel, PixelI * pChannel[16],
    const U8 nLen, const U8 idxCC[16][16], size_t iShift)
{
  IACA_START for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	((pChannel[iChannel & 15]
	  [((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 15]] +
	  iBias) >> iShift);
      p <<= nLen;
      pDst[iChannel] =
	((I16) ((p) < (-32768) ? (-32768) : ((32767) < (p) ? (32767) : (p))));
     } IACA_END
}
