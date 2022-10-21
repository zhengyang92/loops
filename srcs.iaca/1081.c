#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int start, int x, const int limit, const int end, uint16_t * dst,
    const int bg)
{
  for (x = start; x < end; x++)
     { IACA_START
      if (dst[x] != bg)
	{
	  dst[x] = limit;
	  break;
	}
     } IACA_END
}
