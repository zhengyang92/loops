#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int gth, int bth, int dth, int x, int ath, int block,
    ptrdiff_t dst_linesize, int max, uint16_t * dst)
{
  for (x = 0; x < block; x++)
     { IACA_START
      int A, B, C, D, E, F, a, b, c, d, e, f;
      int delta = dst[x] - dst[x - dst_linesize];
      if (((delta) >= 0 ? (delta) : (-(delta))) >= ath
	  || ((dst[x - 1 * dst_linesize] - dst[x - 2 * dst_linesize]) >=
	      0 ? (dst[x - 1 * dst_linesize] -
		   dst[x - 2 * dst_linesize]) : (-(dst[x - 1 * dst_linesize] -
						   dst[x -
						       2 * dst_linesize]))) >=
	  bth
	  || ((dst[x + 1 * dst_linesize] - dst[x + 2 * dst_linesize]) >=
	      0 ? (dst[x + 1 * dst_linesize] -
		   dst[x + 2 * dst_linesize]) : (-(dst[x + 1 * dst_linesize] -
						   dst[x +
						       2 * dst_linesize]))) >=
	  gth
	  || ((dst[x + 0 * dst_linesize] - dst[x + 1 * dst_linesize]) >=
	      0 ? (dst[x + 0 * dst_linesize] -
		   dst[x + 1 * dst_linesize]) : (-(dst[x + 0 * dst_linesize] -
						   dst[x +
						       1 * dst_linesize]))) >=
	  dth)
	continue;
      A = dst[x - 3 * dst_linesize];
      B = dst[x - 2 * dst_linesize];
      C = dst[x - 1 * dst_linesize];
      D = dst[x + 0 * dst_linesize];
      E = dst[x + 1 * dst_linesize];
      F = dst[x + 2 * dst_linesize];
      a = A + delta / 8;
      b = B + delta / 4;
      c = C + delta / 2;
      d = D - delta / 2;
      e = E - delta / 4;
      f = F - delta / 8;
      dst[x - 3 * dst_linesize] = av_clip_c (a, 0, max);
      dst[x - 2 * dst_linesize] = av_clip_c (b, 0, max);
      dst[x - 1 * dst_linesize] = av_clip_c (c, 0, max);
      dst[x + 0 * dst_linesize] = av_clip_c (d, 0, max);
      dst[x + 1 * dst_linesize] = av_clip_c (e, 0, max);
      dst[x + 2 * dst_linesize] = av_clip_c (f, 0, max);
     } IACA_END
}
