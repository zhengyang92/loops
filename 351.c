#include <stdint.h>
#include <stdio.h>






int
fn (double histogram_energies[1000], int i)
{
  for (i = 0; i < 1000; ++i)
    {
      histogram_energies[i] =
	pow (10.0, ((double) i / 10.0 - 69.95 + 0.691) / 10.0);
}}
