#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (const int chroma, const ptrdiff_t stride, const uint8_t rv40_dither_r[16],
    int i, const int lims, const int alpha, const uint8_t rv40_dither_l[16],
    uint8_t * src, const int dmode, const int step)
{
  for (i = 0; i < 4; i++, src += stride)
     { IACA_START
      int sflag, p0, q0, p1, q1;
      int t = src[0 * step] - src[-1 * step];
      if (!t)
	continue;
      sflag = (alpha * ((t) >= 0 ? (t) : (-(t)))) >> 7;
      if (sflag > 1)
	continue;
      p0 =
	(25 * src[-3 * step] + 26 * src[-2 * step] + 26 * src[-1 * step] +
	 26 * src[0 * step] + 25 * src[1 * step] + rv40_dither_l[dmode +
								 i]) >> 7;
      q0 =
	(25 * src[-2 * step] + 26 * src[-1 * step] + 26 * src[0 * step] +
	 26 * src[1 * step] + 25 * src[2 * step] + rv40_dither_r[dmode +
								 i]) >> 7;
      if (sflag)
	{
	  p0 = av_clip_c (p0, src[-1 * step] - lims, src[-1 * step] + lims);
	  q0 = av_clip_c (q0, src[0 * step] - lims, src[0 * step] + lims);
	}
      p1 =
	(25 * src[-4 * step] + 26 * src[-3 * step] + 26 * src[-2 * step] +
	 26 * p0 + 25 * src[0 * step] + rv40_dither_l[dmode + i]) >> 7;
      q1 =
	(25 * src[-1 * step] + 26 * q0 + 26 * src[1 * step] +
	 26 * src[2 * step] + 25 * src[3 * step] + rv40_dither_r[dmode +
								 i]) >> 7;
      if (sflag)
	{
	  p1 = av_clip_c (p1, src[-2 * step] - lims, src[-2 * step] + lims);
	  q1 = av_clip_c (q1, src[1 * step] - lims, src[1 * step] + lims);
	}
      src[-2 * step] = p1;
      src[-1 * step] = p0;
      src[0 * step] = q0;
      src[1 * step] = q1;
      if (!chroma)
	{
	  src[-3 * step] =
	    (25 * src[-1 * step] + 26 * src[-2 * step] + 51 * src[-3 * step] +
	     26 * src[-4 * step] + 64) >> 7;
	  src[2 * step] =
	    (25 * src[0 * step] + 26 * src[1 * step] + 51 * src[2 * step] +
	     26 * src[3 * step] + 64) >> 7;
	}
     } IACA_END
}
