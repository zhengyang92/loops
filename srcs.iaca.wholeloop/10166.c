#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int I32;

int
fn (I32 * pDC, const int blkOffsetUV_422[8], int i, PixelI * pData)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      pDC[i] = pData[blkOffsetUV_422[i]];
     } IACA_END
}
