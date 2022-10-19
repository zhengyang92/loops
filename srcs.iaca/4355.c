#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int gth, int y, int bth, int ath, int block, ptrdiff_t dst_linesize,
    int max, uint16_t * dst)
{
  for (y = 0; y < block; y++)
    {
      int delta = dst[0] - dst[-1];
      int A, B, C, D, a, b, c, d;
      if (((delta) >= 0 ? (delta) : (-(delta))) >= ath
	  || ((dst[-1] - dst[-2]) >=
	      0 ? (dst[-1] - dst[-2]) : (-(dst[-1] - dst[-2]))) >= bth
	  || ((dst[0] - dst[1]) >=
	      0 ? (dst[0] - dst[1]) : (-(dst[0] - dst[1]))) >= gth)
	continue;
      A = dst[-2];
      B = dst[-1];
      C = dst[+0];
      D = dst[+1];
      a = A + delta / 8;
      b = B + delta / 2;
      c = C - delta / 2;
      d = D - delta / 8;
      dst[-2] = av_clip_c (a, 0, max);
      dst[-1] = av_clip_c (b, 0, max);
      dst[+0] = av_clip_c (c, 0, max);
      dst[+1] = av_clip_c (d, 0, max);
      dst += dst_linesize;
    }
}
