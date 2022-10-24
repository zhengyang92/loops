#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, uint32_t x[128], int z, const uint32_t th[2], int k, int a)
{
  IACA_START for (i = 0; i < 2; i++)
    {
      k = (a + i & (128 - 1));
      if (k == z || x[k] < th[i])
	{
	  i = 2;
	  break;
	}
      if (x[a + i & (128 - 1)] > th[i])
	break;
     } IACA_END
}
