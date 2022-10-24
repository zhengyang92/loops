#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int majority_seg, int cnt[4], int NUM_MB_SEGMENTS, int n)
{
  const int majority_cnt_3_x_3_grid = 5;
  IACA_START for (n = 0; n < NUM_MB_SEGMENTS; ++n)
    {
      if (cnt[n] >= majority_cnt_3_x_3_grid)
	{
	  majority_seg = n;
	  break;
	}
     } IACA_END
}
