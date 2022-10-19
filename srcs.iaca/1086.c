#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int y, int offset, const int start, int x, int *emax, const int end,
    uint16_t * dst, const int bg)
{
  for (x = end - 1; x >= start && x >= emax[y - offset]; x--)
    {
      if (dst[x] != bg)
	{
	  emax[y - offset] = x;
	  break;
	}
    }
}
