#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int entry_size, int x, int y3, uint8_t ** data, int plane, int y2,
    int *linesize, int *base, int k, int x3, int j, int x2)
{
  for (k = 0; k < entry_size; k++, j++)
     { IACA_START
      plane = k >= 4 ? k - 3 : 0;
      if (k >= 4)
	{
	  x3 = (x + x2) >> 1;
	  y3 = (y + y2) >> 1;
	}
      else
	{
	  x3 = x + x2 + (k & 1);
	  y3 = y + y2 + (k >> 1);
	}
      base[j] = data[plane][x3 + y3 * linesize[plane]];
     } IACA_END
}
