#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t alpha_step, int alpha, int w, int y, unsigned int max,
    unsigned int u, unsigned int shift, int x, const uint16_t * s,
    int target_table[2][3], int plane, uint16_t * d, const uint16_t * a,
    int y_subsample, unsigned int off)
{
  for (x = 0; x < w; x++)
     { IACA_START
      if (y_subsample)
	{
	  alpha =
	    (av_bswap16 (a[2 * x]) + av_bswap16 (a[2 * x + 1]) + 2 +
	     av_bswap16 (a[2 * x + alpha_step]) +
	     av_bswap16 (a[2 * x + alpha_step + 1])) >> 2;
	}
      else
	alpha = (av_bswap16 (a[2 * x]) + av_bswap16 (a[2 * x + 1])) >> 1;
      u =
	av_bswap16 (s[x]) * alpha +
	target_table[((x ^ y) >> 5) & 1][plane] * (max - alpha) + off;
      d[x] = av_clip_c ((u + (u >> shift)) >> shift, 0, max);
     } IACA_END
}
