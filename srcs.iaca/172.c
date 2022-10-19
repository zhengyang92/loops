#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (double a1, int *clippings, double dry, double a0, double wet, double out,
    double m2, const int32_t * ibuf, double b1, double a2, int len, double m0,
    double b0, double m1, int32_t * obuf, int disabled)
{
  for (int i = 0; i < len; i++)
    {
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
    }
}
