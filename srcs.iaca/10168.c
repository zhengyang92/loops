#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int I32;

int
fn (I32 * pDC, PixelI * pData, int i, const int dctIndex[3][16])
{
  for (i = 0; i < 16; i++)
     { IACA_START
      pDC[i] = pData[dctIndex[2][i]];
     } IACA_END
}
