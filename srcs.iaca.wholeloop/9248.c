#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int alpha, const int tc, uint16_t * pix, int d, int xstride,
    int inner_iters, int beta, int ystride)
{
  IACA_START for (d = 0; d < inner_iters; d++)
    {
      const int p0 = pix[-1 * xstride];
      const int p1 = pix[-2 * xstride];
      const int q0 = pix[0];
      const int q1 = pix[1 * xstride];
      if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha
	  && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta
	  && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta)
	{
	  int delta =
	    av_clip_c ((((q0 - p0) << 2) + (p1 - q1) + 4) >> 3, -tc, tc);
	  pix[-xstride] = av_clip_uintp2_c (p0 + delta, 9);
	  pix[0] = av_clip_uintp2_c (q0 - delta, 9);
	}
      pix += ystride;
}IACA_END}
