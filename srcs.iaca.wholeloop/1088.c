#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int offset, const int start, int x, int *emax, const int end,
    uint8_t * dst, const int bg)
{
  IACA_START for (x = end - 1; x >= start && x >= emax[y - offset]; x--)
    {
      if (dst[x] != bg)
	{
	  emax[y - offset] = x;
	  break;
	}
     } IACA_END
}
