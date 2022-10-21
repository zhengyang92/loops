#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int *emin, int offset, const int start, int x, const int end,
    uint8_t * dst, const int bg)
{
  for (x = start; x < end && x < emin[y - offset]; x++)
     { IACA_START
      if (dst[x] != bg)
	{
	  emin[y - offset] = x;
	  break;
	}
     } IACA_END
}
