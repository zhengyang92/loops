#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double a1, int *clippings, double dry, double *obuf, double w2,
    double wet, double out, const double *ibuf, double a2, double w1, int len,
    double b1, double b0, double in, double w0, int disabled, double b2)
{
  for (int i = 0; i < len; i++)
    {
      in = ibuf[i];
      w0 = in + a1 * w1 + a2 * w2;
      out = b0 * w0 + b1 * w1 + b2 * w2;
      w2 = w1;
      w1 = w0;
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
    }
}
