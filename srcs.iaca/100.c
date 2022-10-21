#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int minperiod, float yy, float yy_lookup[769], float g, int T0, int k,
    float *x, float xy2, int T, float xx, int prev_period, float best_xy,
    float xy, const uint8_t second_check[16], float prev_gain, float g0,
    int maxperiod, float best_yy, int N)
{
  for (k = 2; k <= 15; k++)
     { IACA_START
      int T1, T1b;
      float g1;
      float cont = 0;
      float thresh;
      T1 = (2 * T0 + k) / (2 * k);
      if (T1 < minperiod)
	break;
      if (k == 2)
	{
	  if (T1 + T0 > maxperiod)
	    T1b = T0;
	  else
	    T1b = T0 + T1;
	}
      else
	{
	  T1b = (2 * second_check[k] * T0 + k) / (2 * k);
	}
      dual_inner_prod (x, &x[-T1], &x[-T1b], N, &xy, &xy2);
      xy = .5f * (xy + xy2);
      yy = .5f * (yy_lookup[T1] + yy_lookup[T1b]);
      g1 = compute_pitch_gain (xy, xx, yy);
      if (((T1 - prev_period) >=
	   0 ? (T1 - prev_period) : (-(T1 - prev_period))) <= 1)
	cont = prev_gain;
      else
	if (((T1 - prev_period) >=
	     0 ? (T1 - prev_period) : (-(T1 - prev_period))) <= 2
	    && 5 * k * k < T0)
	cont = prev_gain * .5f;
      else
	cont = 0;
      thresh = ((.3f) > ((.7f * g0) - cont) ? (.3f) : ((.7f * g0) - cont));
      if (T1 < 3 * minperiod)
	thresh =
	  ((.4f) > ((.85f * g0) - cont) ? (.4f) : ((.85f * g0) - cont));
      else if (T1 < 2 * minperiod)
	thresh = ((.5f) > ((.9f * g0) - cont) ? (.5f) : ((.9f * g0) - cont));
      if (g1 > thresh)
	{
	  best_xy = xy;
	  best_yy = yy;
	  T = T1;
	  g = g1;
	}
     } IACA_END
}
