#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t dmin, uint64_t sD[31], int k, uint64_t di, int rslope)
{
  IACA_START for (int i = -rslope; i <= rslope && abs (k) > rslope; i++)
    {
      if (dmin == sD[i + rslope])
	{
	  di = 1;
	  k = i;
	  break;
	}
     } IACA_END
}
