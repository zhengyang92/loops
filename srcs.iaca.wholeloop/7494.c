#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int gth, int y, int bth, int dth, int ath, uint8_t * dst, int block,
    ptrdiff_t dst_linesize, int max)
{
  IACA_START for (y = 0; y < block; y++)
    {
      int A, B, C, D, E, F, a, b, c, d, e, f;
      int delta = dst[0] - dst[-1];
      if (((delta) >= 0 ? (delta) : (-(delta))) >= ath
	  || ((dst[-1] - dst[-2]) >=
	      0 ? (dst[-1] - dst[-2]) : (-(dst[-1] - dst[-2]))) >= bth
	  || ((dst[+1] - dst[+2]) >=
	      0 ? (dst[+1] - dst[+2]) : (-(dst[+1] - dst[+2]))) >= gth
	  || ((dst[+0] - dst[+1]) >=
	      0 ? (dst[+0] - dst[+1]) : (-(dst[+0] - dst[+1]))) >= dth)
	continue;
      A = dst[-3];
      B = dst[-2];
      C = dst[-1];
      D = dst[+0];
      E = dst[+1];
      F = dst[+2];
      a = A + delta / 8;
      b = B + delta / 4;
      c = C + delta / 2;
      d = D - delta / 2;
      e = E - delta / 4;
      f = F - delta / 8;
      dst[-3] = av_clip_c (a, 0, max);
      dst[-2] = av_clip_c (b, 0, max);
      dst[-1] = av_clip_c (c, 0, max);
      dst[+0] = av_clip_c (d, 0, max);
      dst[+1] = av_clip_c (e, 0, max);
      dst[+2] = av_clip_c (f, 0, max);
      dst += dst_linesize;
     } IACA_END
}
