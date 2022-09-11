#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (Int j, PixelI * pOrg)
{
  for (j = 32; j <= 48; j += 16)
    {
      pOrg[j + 5] -= pOrg[j + 5 - 32];
      pOrg[j + 1] -= pOrg[j + 1 - 32];
      pOrg[j + 6] -= pOrg[j + 6 - 32];
    }
}
