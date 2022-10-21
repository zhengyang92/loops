#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *lut, int N, int n)
{
  for (n = 0; n < N; n++)
     { IACA_START
      double x = 2 * ((n / (double) (N - 1)) - .5);
      if (x <= -.5 || x >= .5)
	{
	  lut[n] = 0;
	}
      else
	{
	  lut[n] =
	    ((1) >
	     (fabs (1 / (1 + 4 * 16 * x * x)))
	     ? (fabs (1 / (1 + 4 * 16 * x * x))) : (1));
	}
     } IACA_END
}
