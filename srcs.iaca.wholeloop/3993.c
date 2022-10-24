#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int rp, int i, uint32_t x[128], int z, int k, uint32_t carry, int a)
{
  int sh = 1;
  IACA_START for (k = a; k != z; k = (k + 1 & (128 - 1)))
    {
      uint32_t tmp = x[k] & (1 << sh) - 1;
      x[k] = (x[k] >> sh) + carry;
      carry = (1000000000 >> sh) * tmp;
      if (k == a && !x[k])
	{
	  a = (a + 1 & (128 - 1));
	  i--;
	  rp -= 9;
	}
     } IACA_END
}
