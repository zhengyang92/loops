#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *lut, int N, int n)
{
  for (n = 0; n < N; n++)
    {
      double x = 2 * ((n / (double) (N - 1)) - .5);
      if (x > 0.25 && x <= 0.5)
	{
	  lut[n] = -2 * powf (-1 + 2 * x, 3);
	}
      else if (x >= -.5 && x < -.25)
	{
	  lut[n] = 2 * powf (1 + 2 * x, 3);
	}
      else if (x >= -.25 && x < 0)
	{
	  lut[n] = 1 - 24 * x * x - 48 * x * x * x;
	}
      else if (x >= 0 && x <= .25)
	{
	  lut[n] = 1 - 24 * x * x + 48 * x * x * x;
	}
      else
	{
	  lut[n] = 0;
	}
    }
}
