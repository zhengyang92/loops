#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int diff, const ptrdiff_t stride, const int beta, int i, int u, int t,
    const int lim_q1, const int alpha, const int lim_p1, const int lim_p0q0,
    const uint8_t * cm, const int filter_q1, uint8_t * src,
    const int filter_p1, const int step)
{
  IACA_START for (i = 0; i < 4; i++, src += stride)
    {
      int diff_p1p0 = src[-2 * step] - src[-1 * step];
      int diff_q1q0 = src[1 * step] - src[0 * step];
      int diff_p1p2 = src[-2 * step] - src[-3 * step];
      int diff_q1q2 = src[1 * step] - src[2 * step];
      t = src[0 * step] - src[-1 * step];
      if (!t)
	continue;
      u = (alpha * ((t) >= 0 ? (t) : (-(t)))) >> 7;
      if (u > 3 - (filter_p1 && filter_q1))
	continue;
      t *= 1 << 2;
      if (filter_p1 && filter_q1)
	t += src[-2 * step] - src[1 * step];
      diff = av_clip_c ((t + 4) >> 3, -(lim_p0q0), lim_p0q0);
      src[-1 * step] = cm[src[-1 * step] + diff];
      src[0 * step] = cm[src[0 * step] - diff];
      if (filter_p1
	  && ((diff_p1p2) >= 0 ? (diff_p1p2) : (-(diff_p1p2))) <= beta)
	{
	  t = (diff_p1p0 + diff_p1p2 - diff) >> 1;
	  src[-2 * step] =
	    cm[src[-2 * step] - av_clip_c (t, -(lim_p1), lim_p1)];
	}
      if (filter_q1
	  && ((diff_q1q2) >= 0 ? (diff_q1q2) : (-(diff_q1q2))) <= beta)
	{
	  t = (diff_q1q0 + diff_q1q2 + diff) >> 1;
	  src[1 * step] =
	    cm[src[1 * step] - av_clip_c (t, -(lim_q1), lim_q1)];
	}
     } IACA_END
}
