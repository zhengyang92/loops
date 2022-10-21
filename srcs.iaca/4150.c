#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double a1, int *clippings, double dry, double *obuf, double wet,
    double s0, double out, const double *ibuf, double b1, double s1,
    double t0, double t1, int len, double a2, double in, double b0,
    int disabled, double b2)
{
  for (int i = 0; i < len; i++)
     { IACA_START
      in = ibuf[i];
      out = b2 * in + s0;
      t0 = b0 * in + a1 * s0 + s1;
      t1 = b1 * in + a2 * s0;
      s0 = t0;
      s1 = t1;
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
