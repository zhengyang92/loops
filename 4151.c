#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (double a1, int *clippings, double dry, int16_t * obuf, double a0,
    double wet, double out, double m2, double b1, double b0, double m0,
    int len, double a2, const int16_t * ibuf, double m1, int disabled)
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
    }
}
