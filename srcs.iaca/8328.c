#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (double a1, int *clippings, double dry, int16_t * obuf, double w2,
    double wet, double out, double a2, double b0, int len, double w1,
    double b1, double in, const int16_t * ibuf, int disabled, double b2)
{
  for (int i = 0; i < len; i++)
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
