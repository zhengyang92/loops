#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (const int no_p, uint16_t * pix, const int tc2, int d, ptrdiff_t ystride,
    ptrdiff_t xstride, const int no_q)
{
  for (d = 0; d < 4; d++)
    {
      const int p3 = pix[-4 * xstride];
      const int p2 = pix[-3 * xstride];
      const int p1 = pix[-2 * xstride];
      const int p0 = pix[-1 * xstride];
      const int q0 = pix[0 * xstride];
      const int q1 = pix[1 * xstride];
      const int q2 = pix[2 * xstride];
      const int q3 = pix[3 * xstride];
      if (!no_p)
	{
	  pix[-1 * xstride] =
	    p0 + av_clip_c (((p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3) -
			    p0, -tc2, tc2);
	  pix[-2 * xstride] =
	    p1 + av_clip_c (((p2 + p1 + p0 + q0 + 2) >> 2) - p1, -tc2, tc2);
	  pix[-3 * xstride] =
	    p2 + av_clip_c (((2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3) - p2,
			    -tc2, tc2);
	}
      if (!no_q)
	{
	  pix[0 * xstride] =
	    q0 + av_clip_c (((p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3) -
			    q0, -tc2, tc2);
	  pix[1 * xstride] =
	    q1 + av_clip_c (((p0 + q0 + q1 + q2 + 2) >> 2) - q1, -tc2, tc2);
	  pix[2 * xstride] =
	    q2 + av_clip_c (((2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3) - q2,
			    -tc2, tc2);
	}
      pix += ystride;
    }
}
