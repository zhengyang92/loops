#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int *cmap, int i, int d, uint32_t pseudopal[4], int best_d, int j,
    const uint32_t * palette)
{
  for (j = 0; j < 4; j++)
     { IACA_START
      d = color_distance (pseudopal[j], palette[i]);
      if (d < best_d)
	{
	  cmap[i] = j;
	  best_d = d;
	}
     } IACA_END
}
