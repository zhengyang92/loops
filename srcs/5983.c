#include <stdint.h>
#include <stdio.h>






int
fn (double p, double l2tab[256], double occ[256], double len, int m)
{
  for (m = 1; m < 256; m++)
    if (occ[m])
      {
	len -= occ[m] * (p * l2tab[m] + (1 - p) * l2tab[256 - m]);
      }
}
