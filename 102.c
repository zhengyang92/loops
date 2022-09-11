#include <stdint.h>
#include <stdio.h>






int
fn (float xcorr[960], int max_pitch, int best_pitch[2], const float *x_lp,
    int len, float *y)
{
  for (int i = 0; i < max_pitch >> 1; i++)
    {
      float sum;
      xcorr[i] = 0;
      if (((i - 2 * best_pitch[0]) >=
	   0 ? (i - 2 * best_pitch[0]) : (-(i - 2 * best_pitch[0]))) > 2
	  && ((i - 2 * best_pitch[1]) >=
	      0 ? (i - 2 * best_pitch[1]) : (-(i - 2 * best_pitch[1]))) > 2)
	continue;
      sum = celt_inner_prod (x_lp, y + i, len >> 1);
      xcorr[i] = ((-1) > (sum) ? (-1) : (sum));
    }
}
