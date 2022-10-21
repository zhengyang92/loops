#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t coarse[16], int k, const int t, int sum)
{
  for (k = 0; k < (1 << ((8 + 1) / 2)); k++)
     { IACA_START
      sum += coarse[k];
      if (sum > t)
	{
	  sum -= coarse[k];
	  break;
	}
     } IACA_END
}
