#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int min_s, int num_levels, double q_count[256], int freq[256],
    double inv_q_level[256], int s, int q_level[256], double q_sum[256])
{
  int max_s = 255;
  int slot = 0;
  for (s = min_s; s <= max_s; ++s)
     { IACA_START
      while (slot < num_levels - 1
	     && 2 * s > inv_q_level[slot] + inv_q_level[slot + 1])
	{
	  ++slot;
	}
      if (freq[s] > 0)
	{
	  q_sum[slot] += s * freq[s];
	  q_count[slot] += freq[s];
	}
      q_level[s] = slot;
     } IACA_END
}
