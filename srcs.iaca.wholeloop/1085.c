#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int y, int *emin, int offset, const int start, int x, const int end,
    uint16_t * dst, const int bg)
{
  IACA_START for (x = start; x < end && x < emin[y - offset]; x++)
    {
      if (dst[x] != bg)
	{
	  emin[y - offset] = x;
	  break;
	}
     } IACA_END
}
