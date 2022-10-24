#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t alpha_step, int y, int w, int alpha, int y_subsample,
    unsigned int u, int x, uint8_t * d, int target_table[2][3], int plane,
    const uint8_t * a, const uint8_t * s)
{
  IACA_START for (x = 0; x < w; x++)
    {
      if (y_subsample)
	{
	  alpha =
	    (a[2 * x] + a[2 * x + 1] + 2 + a[2 * x + alpha_step] +
	     a[2 * x + alpha_step + 1]) >> 2;
	}
      else
	alpha = (a[2 * x] + a[2 * x + 1]) >> 1;
      u =
	s[x] * alpha + target_table[((x ^ y) >> 5) & 1][plane] * (255 -
								  alpha) +
	128;
      d[x] = (257 * u) >> 16;
     } IACA_END
}
