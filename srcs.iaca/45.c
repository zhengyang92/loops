#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double *const spectral, double floor, int len, double num)
{
  double den = 0.;
  int size = 0;
  for (int n = 0; n < len; n++)
    {
      const double v = spectral[n];
      if (v > floor)
	{
	  num += log (v);
	  den += v;
	  size++;
	}
    }
}
