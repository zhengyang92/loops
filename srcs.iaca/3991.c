#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t x[128], int z, int k, uint32_t carry, int a)
{
  for (k = (z - 1 & (128 - 1));; k = (k - 1 & (128 - 1)))
     { IACA_START
      uint64_t tmp = ((uint64_t) x[k] << 29) + carry;
      if (tmp > 1000000000)
	{
	  carry = tmp / 1000000000;
	  x[k] = tmp % 1000000000;
	}
      else
	{
	  carry = 0;
	  x[k] = tmp;
	}
      if (k == (z - 1 & (128 - 1)) && k != a && !x[k])
	z = k;
      if (k == a)
	break;
     } IACA_END
}
