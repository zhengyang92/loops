#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int no_q, const int tc, int d, uint16_t * pix, ptrdiff_t ystride,
    int no_p, ptrdiff_t xstride)
{
  for (d = 0; d < 4; d++)
     { IACA_START
      int delta0;
      const int p1 = pix[-2 * xstride];
      const int p0 = pix[-1 * xstride];
      const int q0 = pix[0 * xstride];
      const int q1 = pix[1 * xstride];
      delta0 = av_clip_c ((((q0 - p0) * 4) + p1 - q1 + 4) >> 3, -tc, tc);
      if (!no_p)
	pix[-1 * xstride] = av_clip_uintp2_c (p0 + delta0, 9);
      if (!no_q)
	pix[0 * xstride] = av_clip_uintp2_c (q0 - delta0, 9);
      pix += ystride;
     } IACA_END
}
