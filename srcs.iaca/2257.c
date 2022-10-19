#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int alpha, uint16_t * pix, int d, int inner_iters, ptrdiff_t ystride,
    int beta, ptrdiff_t xstride)
{
  for (d = 0; d < 4 * inner_iters; d++)
    {
      const int p0 = pix[-1 * xstride];
      const int p1 = pix[-2 * xstride];
      const int q0 = pix[0];
      const int q1 = pix[1 * xstride];
      if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha
	  && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta
	  && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta)
	{
	  pix[-xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
	  pix[0] = (2 * q1 + q0 + p1 + 2) >> 2;
	}
      pix += ystride;
    }
}
