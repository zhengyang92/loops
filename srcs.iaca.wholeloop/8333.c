#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (double v1, int *clippings, double dry, double wet, double s0, double out,
    double v2, const int32_t * ibuf, double k1, int len, double t0, double t1,
    double in, double s1, double k0, int32_t * obuf, int disabled, double v0)
{
  IACA_START for (int i = 0; i < len; i++)
    {
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
      else if (1 && out < (-2147483647 - 1))
	{
	  (*clippings)++;
	  obuf[i] = (-2147483647 - 1);
	}
      else if (1 && out > (2147483647))
	{
	  (*clippings)++;
	  obuf[i] = (2147483647);
	}
      else
	{
	  obuf[i] = out;
	}
     } IACA_END
}
