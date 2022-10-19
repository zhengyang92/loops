#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (Int k, Int j, PixelI * pOrg)
{
  for (j = 192; j > 0; j -= 64)
    {
      pOrg[k + j + 5] -= pOrg[k + j + 5 - 64];
      pOrg[k + j + 1] -= pOrg[k + j + 1 - 64];
      pOrg[k + j + 6] -= pOrg[k + j + 6 - 64];
    }
}
