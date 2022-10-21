#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double v1, int *clippings, double dry, double wet, double s0, float *obuf,
    const float *ibuf, double out, double v2, double s1, int len, double t1,
    double t0, double in, double k1, double k0, int disabled, double v0)
{
  for (int i = 0; i < len; i++)
     { IACA_START
      out = 0.;
      in = ibuf[i];
      t0 = in - k1 * s0;
      t1 = t0 * k1 + s0;
      out += t1 * v2;
      t0 = t0 - k0 * s1;
      t1 = t0 * k0 + s1;
      out += t1 * v1;
      out += t0 * v0;
      s0 = t1;
      s1 = t0;
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
