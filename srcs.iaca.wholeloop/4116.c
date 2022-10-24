#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float best_num[2], float best_den[2], int max_pitch, int *best_pitch,
    int len, float *xcorr, float *y)
{
  float Syy = 1.f;
  IACA_START for (int i = 0; i < max_pitch; i++)
    {
      if (xcorr[i] > 0)
	{
	  float num;
	  float xcorr16;
	  xcorr16 = xcorr[i];
	  xcorr16 *= 1e-12f;
	  num = xcorr16 * xcorr16;
	  if ((num * best_den[1]) > (best_num[1] * Syy))
	    {
	      if ((num * best_den[0]) > (best_num[0] * Syy))
		{
		  best_num[1] = best_num[0];
		  best_den[1] = best_den[0];
		  best_pitch[1] = best_pitch[0];
		  best_num[0] = num;
		  best_den[0] = Syy;
		  best_pitch[0] = i;
		}
	      else
		{
		  best_num[1] = num;
		  best_den[1] = Syy;
		  best_pitch[1] = i;
		}
	    }
	}
      Syy += y[i + len] * y[i + len] - y[i] * y[i];
      Syy = ((1) > (Syy) ? (1) : (Syy));
     } IACA_END
}
