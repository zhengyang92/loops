#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *lut, int N, int n)
{
  for (n = 0; n < N; n++)
     { IACA_START
      float M = (N - 1) / 2.;
      if (((n - M) >= 0 ? (n - M) : (-(n - M))) >= 0.3 * M)
	{
	  lut[n] =
	    0.5 * (1 +
		   cos ((3.14159265358979323846 *
			 (((n - M) >=
			   0 ? (n - M) : (-(n - M))) - 0.3 * M)) / ((1 -
								     0.3) *
								    M)));
	}
      else
	{
	  lut[n] = 1;
	}
     } IACA_END
}
