#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (double a1, int *clippings, double dry, int16_t * obuf, double w2,
    double wet, double out, double b1, double w1, int len, double in,
    double b0, const int16_t * ibuf, double a2, double w0, int disabled,
    double b2)
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
