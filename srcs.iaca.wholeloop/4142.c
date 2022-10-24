#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double a1, int *clippings, double dry, double *obuf, double w2,
    double wet, double out, const double *ibuf, double b1, double w1,
    double a2, int len, double b0, double in, int disabled, double b2)
{
  IACA_START for (int i = 0; i < len; i++)
    {
      in = ibuf[i];
      out = b0 * in + w1;
      w1 = b1 * in + w2 + a1 * out;
      w2 = b2 * in + a2 * out;
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
