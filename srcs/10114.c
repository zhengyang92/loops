#include <stdint.h>
#include <stdio.h>






int
fn (int num_levels, double q_sum[256], double q_count[256],
    double inv_q_level[256])
{
  int slot = 0;
  for (slot = 1; slot < num_levels - 1; ++slot)
    {
      const double count = q_count[slot];
      if (count > 0.)
	{
	  inv_q_level[slot] = q_sum[slot] / count;
	}
    }
}
