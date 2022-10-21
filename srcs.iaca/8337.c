#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (double a1, int *clippings, double dry, double wet, const int32_t * ibuf,
    double out, double s0, double b1, double s1, double t0, double a2,
    double t1, double in, int len, double b0, int32_t * obuf, int disabled,
    double b2)
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
