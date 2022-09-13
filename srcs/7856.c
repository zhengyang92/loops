#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int alpha, uint16_t * pix, const int tc_orig, int d, int inner_iters,
    int beta, ptrdiff_t ystride, ptrdiff_t xstride)
{
  for (d = 0; d < inner_iters; d++)
    {
      const int p0 = pix[-1 * xstride];
      const int p1 = pix[-2 * xstride];
      const int p2 = pix[-3 * xstride];
      const int q0 = pix[0];
      const int q1 = pix[1 * xstride];
      const int q2 = pix[2 * xstride];
      if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha
	  && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta
	  && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta)
	{
	  int tc = tc_orig;
	  int i_delta;
	  if (((p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0))) < beta)
	    {
	      if (tc_orig)
		pix[-2 * xstride] =
		  p1 + av_clip_c (((p2 + ((p0 + q0 + 1) >> 1)) >> 1) - p1,
				  -tc_orig, tc_orig);
	      tc++;
	    }
	  if (((q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0))) < beta)
	    {
	      if (tc_orig)
		pix[xstride] =
		  q1 + av_clip_c (((q2 + ((p0 + q0 + 1) >> 1)) >> 1) - q1,
				  -tc_orig, tc_orig);
	      tc++;
	    }
	  i_delta =
	    av_clip_c ((((q0 - p0) * 4) + (p1 - q1) + 4) >> 3, -tc, tc);
	  pix[-xstride] = av_clip_uintp2_c (p0 + i_delta, 14);
	  pix[0] = av_clip_uintp2_c (q0 - i_delta, 14);
	}
      pix += ystride;
    }
}
