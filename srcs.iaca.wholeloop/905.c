#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int k, uint16_t coarse[64], const int t, int sum)
{
  IACA_START for (k = 0; k < (1 << ((12 + 1) / 2)); k++)
    {
      sum += coarse[k];
      if (sum > t)
	{
	  sum -= coarse[k];
	  break;
	}
     } IACA_END
}
