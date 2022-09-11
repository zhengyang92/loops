#include <stdint.h>
#include <stdio.h>






int
fn (int displaced, const int nb, int accum[4], int dist_accum[4], int n,
    int centers[4], int total_weight)
{
  int weighted_average = 0;
  for (n = 0; n < nb; ++n)
    {
      if (accum[n])
	{
	  const int new_center = (dist_accum[n] + accum[n] / 2) / accum[n];
	  displaced += abs (centers[n] - new_center);
	  centers[n] = new_center;
	  weighted_average += new_center * accum[n];
	  total_weight += accum[n];
	}
}}
