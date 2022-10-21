#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int gth, int bth, int x, int ath, uint8_t * dst, int block,
    ptrdiff_t dst_linesize, int max)
{
  for (x = 0; x < block; x++)
     { IACA_START
      int delta = dst[x] - dst[x - dst_linesize];
      int A, B, C, D, a, b, c, d;
      if (((delta) >= 0 ? (delta) : (-(delta))) >= ath
	  || ((dst[x - 1 * dst_linesize] - dst[x - 2 * dst_linesize]) >=
	      0 ? (dst[x - 1 * dst_linesize] -
		   dst[x - 2 * dst_linesize]) : (-(dst[x - 1 * dst_linesize] -
						   dst[x -
						       2 * dst_linesize]))) >=
	  bth
	  || ((dst[x + 0 * dst_linesize] - dst[x + 1 * dst_linesize]) >=
	      0 ? (dst[x + 0 * dst_linesize] -
		   dst[x + 1 * dst_linesize]) : (-(dst[x + 0 * dst_linesize] -
						   dst[x +
						       1 * dst_linesize]))) >=
	  gth)
	continue;
      A = dst[x - 2 * dst_linesize];
      B = dst[x - 1 * dst_linesize];
      C = dst[x + 0 * dst_linesize];
      D = dst[x + 1 * dst_linesize];
      a = A + delta / 8;
      b = B + delta / 2;
      c = C - delta / 2;
      d = D - delta / 8;
      dst[x - 2 * dst_linesize] = av_clip_c (a, 0, max);
      dst[x - 1 * dst_linesize] = av_clip_c (b, 0, max);
      dst[x + 0 * dst_linesize] = av_clip_c (c, 0, max);
      dst[x + 1 * dst_linesize] = av_clip_c (d, 0, max);
     } IACA_END
}
