#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (Int j, PixelI * pOrg)
{
  for (j = 16; j <= 48; j += 32)
     { IACA_START
      pOrg[j + 10] -= pOrg[j + 10 - 16];
      pOrg[j + 2] -= pOrg[j + 2 - 16];
      pOrg[j + 9] -= pOrg[j + 9 - 16];
     } IACA_END
}
