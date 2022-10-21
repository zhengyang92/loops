#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (PixelI * pSrc, Int j, const int blkOffsetUV_422[8], PixelI * pOrg,
    PixelI * pRef)
{
  for (j = 2; j < 8; j++)
     { IACA_START
      pOrg = pSrc + blkOffsetUV_422[j];
      pRef = pOrg - 16;
      pOrg[10] += pRef[10];
      pOrg[2] += pRef[2];
      pOrg[9] += pRef[9];
     } IACA_END
}
