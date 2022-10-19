#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const int no_p, const int tc_2, const int tc, uint16_t * pix, int d,
    ptrdiff_t ystride, ptrdiff_t xstride, const int no_q)
{
  int nd_p = 1;
  int nd_q = 1;
  for (d = 0; d < 4; d++)
    {
      const int p2 = pix[-3 * xstride];
      const int p1 = pix[-2 * xstride];
      const int p0 = pix[-1 * xstride];
      const int q0 = pix[0 * xstride];
      const int q1 = pix[1 * xstride];
      const int q2 = pix[2 * xstride];
      int delta0 = (9 * (q0 - p0) - 3 * (q1 - p1) + 8) >> 4;
      if (abs (delta0) < 10 * tc)
	{
	  delta0 = av_clip_c (delta0, -tc, tc);
	  if (!no_p)
	    pix[-1 * xstride] = av_clip_uintp2_c (p0 + delta0, 9);
	  if (!no_q)
	    pix[0 * xstride] = av_clip_uintp2_c (q0 - delta0, 9);
	  if (!no_p && nd_p > 1)
	    {
	      const int deltap1 =
		av_clip_c ((((p2 + p0 + 1) >> 1) - p1 + delta0) >> 1, -tc_2,
			   tc_2);
	      pix[-2 * xstride] = av_clip_uintp2_c (p1 + deltap1, 9);
	    }
	  if (!no_q && nd_q > 1)
	    {
	      const int deltaq1 =
		av_clip_c ((((q2 + q0 + 1) >> 1) - q1 - delta0) >> 1, -tc_2,
			   tc_2);
	      pix[1 * xstride] = av_clip_uintp2_c (q1 + deltaq1, 9);
	    }
	}
      pix += ystride;
}}
