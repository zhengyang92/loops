#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * dst0, uint16_t * dst1, const uint16_t * src, const int t0,
    int x, const int slicew_end, const int slicew_start, const int t1,
    const int bg, const int step)
{
  for (x = slicew_start * step; x < slicew_end * step; x++)
     { IACA_START
      if (src[x] != bg)
	{
	  dst0[x] = t0;
	  dst1[x] = t1;
	}
     } IACA_END
}
