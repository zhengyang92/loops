#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int idx, int32_t * map, int n)
{
  for (idx = 0; idx <= n; ++idx)
     { IACA_START
      do
	{
	  if (0)
	    av_log (((void *) 0), 48,
		    "floor0 map: map at pos %d is %" "d" "\n", idx, map[idx]);
	}
      while (0);
     } IACA_END
}
