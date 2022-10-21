#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double a1, int *clippings, double dry, double *obuf, double wet,
    double m2, double out, const double *ibuf, double b1, double b0, int len,
    double a2, double m0, double a0, double m1, int disabled)
{
  for (int i = 0; i < len; i++)
     { IACA_START
      const double in = ibuf[i];
      const double v0 = in;
      const double v3 = v0 - b1;
      const double v1 = a0 * b0 + a1 * v3;
      const double v2 = b1 + a1 * b0 + a2 * v3;
      b0 = 2. * v1 - b0;
      b1 = 2. * v2 - b1;
      out = m0 * v0 + m1 * v1 + m2 * v2;
      out = out * wet + in * dry;
      if (disabled)
	{
	  obuf[i] = in;
	}
      else if (0 && out < -1.)
	{
	  (*clippings)++;
	  obuf[i] = -1.;
	}
      else if (0 && out > 1.)
	{
	  (*clippings)++;
	  obuf[i] = 1.;
	}
      else
	{
	  obuf[i] = out;
	}
     } IACA_END
}
