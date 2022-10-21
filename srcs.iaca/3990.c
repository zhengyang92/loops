#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int rp, int p10, uint32_t x[128], int z, int k, uint32_t carry, int a)
{
  for (k = a; k != z; k++)
     { IACA_START
      uint32_t tmp = x[k] % p10;
      x[k] = x[k] / p10 + carry;
      carry = 1000000000 / p10 * tmp;
      if (k == a && !x[k])
	{
	  a = (a + 1 & (128 - 1));
	  rp -= 9;
	}
     } IACA_END
}
