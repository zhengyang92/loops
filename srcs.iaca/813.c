#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *lut, int N, int n)
{
  for (n = 0; n < N; n++)
    {
      double x = 2 * ((n / (double) (N - 1)) - .5);
      if (x >= 0 && x <= .5)
	{
	  lut[n] = exp (-6 * x);
	}
      else if (x < 0 && x >= -.5)
	{
	  lut[n] = exp (6 * x);
	}
      else
	{
	  lut[n] = 0;
	}
    }
}
