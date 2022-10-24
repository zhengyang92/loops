#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * curr_row, uint32_t * prev_row, int x, uint32_t * next_row,
    int limit_bits, const int limit, uint32_t * argb_dst, int xsize)
{
  IACA_START for (x = 1; x < xsize - 1; ++x)
    {
      if (IsSmooth (prev_row, curr_row, next_row, x, limit))
	{
	  argb_dst[x] = curr_row[x];
	}
      else
	{
	  argb_dst[x] = ClosestDiscretizedArgb (curr_row[x], limit_bits);
	}
     } IACA_END
}
