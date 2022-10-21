#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (Int j, PixelI * pOrg)
{
  for (j = 64; j <= 112; j += 16)
     { IACA_START
      pOrg[j + 5] -= pOrg[j + 5 - 64];
      pOrg[j + 1] -= pOrg[j + 1 - 64];
      pOrg[j + 6] -= pOrg[j + 6 - 64];
     } IACA_END
}
