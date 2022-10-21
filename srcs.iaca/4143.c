#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (double v1, int *clippings, double dry, int16_t * obuf, double wet,
    double s0, double out, double v2, double k1, double in, int len,
    double t1, const int16_t * ibuf, double t0, double k0, double s1,
    int disabled, double v0)
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
      else if (1 && out < (-32767 - 1))
	{
	  (*clippings)++;
	  obuf[i] = (-32767 - 1);
	}
      else if (1 && out > (32767))
	{
	  (*clippings)++;
	  obuf[i] = (32767);
	}
      else
	{
	  obuf[i] = out;
	}
     } IACA_END
}
