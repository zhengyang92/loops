#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int dist, int cr, int cg, int cb, uint8_t * pal)
{
  int best = 2147483647;
  int index = 0;
  IACA_START for (int k = 0; k < 256; k++)
    {
      int pr = pal[k * 4 + 0];
      int pg = pal[k * 4 + 1];
      int pb = pal[k * 4 + 2];
      dist =
	((cr - pr) >= 0 ? (cr - pr) : (-(cr - pr))) + ((cg - pg) >=
						       0 ? (cg -
							    pg) : (-(cg -
								     pg))) +
	((cb - pb) >= 0 ? (cb - pb) : (-(cb - pb)));
      if (dist < best)
	{
	  best = dist;
	  index = k;
	}
     } IACA_END
}
