#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int max_a, const int nb, int accum[4], int dist_accum[4], int n,
    const int *alphas, int map[256], int a, int centers[4], int min_a)
{
  IACA_START for (a = min_a; a <= max_a; ++a)
    {
      if (alphas[a])
	{
	  while (n + 1 < nb
		 && abs (a - centers[n + 1]) < abs (a - centers[n]))
	    {
	      n++;
	    }
	  map[a] = n;
	  dist_accum[n] += a * alphas[a];
	  accum[n] += alphas[a];
	}
     } IACA_END
}
