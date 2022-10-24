#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double a1, int *clippings, int i, double dry, double *obuf, double i2,
    double wet, double o2, double out, const double *ibuf, double b1,
    double b0, int len, double a2, double o1, double i1, int disabled,
    double b2)
{
  IACA_START for (i = 0; i + 1 < len; i++)
    {
      o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
      i2 = ibuf[i];
      out = o2 * wet + i2 * dry;
      if (disabled)
	{
	  obuf[i] = i2;
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
      i++;
      o1 = i1 * b2 + i2 * b1 + ibuf[i] * b0 + o1 * a2 + o2 * a1;
      i1 = ibuf[i];
      out = o1 * wet + i1 * dry;
      if (disabled)
	{
	  obuf[i] = i1;
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
