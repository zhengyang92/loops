#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int stride, int i, int p, int width, int rows_to_go, uint8_t * dst,
    int run)
{
  int filled = 0;
  for (i = 0; i < run; i++)
     { IACA_START
      dst[filled++] = p;
      if (filled >= width)
	{
	  filled = 0;
	  dst -= stride;
	  rows_to_go--;
	  if (rows_to_go <= 0)
	    break;
	}
     } IACA_END
}
