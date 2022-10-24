#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *pred, int i, float *delta, int n, float *truth, float *error)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      float diff = truth[i] - pred[i];
      float abs_val = fabs (diff);
      if (abs_val < 1)
	{
	  error[i] = diff * diff;
	  delta[i] = diff;
	}
      else
	{
	  error[i] = 2 * abs_val - 1;
	  delta[i] = (diff < 0) ? 1 : -1;
	}
     } IACA_END
}
