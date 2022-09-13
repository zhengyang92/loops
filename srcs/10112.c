#include <stdint.h>
#include <stdio.h>






int
fn (int min_s, int num_levels, int i, double inv_q_level[256])
{
  int max_s = 255;
  for (i = 0; i < num_levels; ++i)
    {
      inv_q_level[i] =
	min_s + (double) (max_s - min_s) * i / (num_levels - 1);
}}
