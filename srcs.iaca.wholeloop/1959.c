#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, uint32_t refcolor[3], int selected[4], int best_d,
    uint32_t pseudopal[33], int j)
{
  IACA_START for (j = i + 1; j < 4; j++)
    {
      int d = color_distance (refcolor[i], pseudopal[selected[j]]);
      if (d < best_d)
	{
	  do
	    {
	      int SWAP_tmp = selected[j];
	      selected[j] = selected[i];
	      selected[i] = SWAP_tmp;
	    }
	  while (0);
	  best_d = d;
	}
     } IACA_END
}
