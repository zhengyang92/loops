#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef unsigned char U8;
typedef int Int;

int
fn (PixelI * pSrc, Int j, U8 blkIdx[12], PixelI * pOrg, PixelI * pRef)
{
  IACA_START for (j = 0; j < sizeof (blkIdx) / sizeof (*blkIdx); ++j)
    {
      pOrg = pSrc + 16 * blkIdx[j];
      pRef = pOrg - 16;
      pOrg[2] += pRef[2];
      pOrg[10] += pRef[10];
      pOrg[9] += pRef[9];
     } IACA_END
}
