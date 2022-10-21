#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int I32;

int
fn (I32 * pDC, int i, PixelI * pData, const int blkOffsetUV[4])
{
  for (i = 0; i < 4; i++)
     { IACA_START
      pDC[i] = pData[blkOffsetUV[i]];
     } IACA_END
}
