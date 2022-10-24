#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int count[16], int len, int offset[16])
{
  IACA_START for (len = 1; len < 15; ++len)
    {
      if (count[len] > (1 << len))
	{
	  return 0;
	}
      offset[len + 1] = offset[len] + count[len];
     } IACA_END
}
