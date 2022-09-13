#include <stdint.h>
#include <stdio.h>






int
fn (double histogram_energy_boundaries[1001], int i)
{
  for (i = 1; i < 1001; ++i)
    {
      histogram_energy_boundaries[i] =
	pow (10.0, ((double) i / 10.0 - 70.0 + 0.691) / 10.0);
}}
