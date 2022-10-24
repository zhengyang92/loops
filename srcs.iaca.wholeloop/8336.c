#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (double a1, int *clippings, double dry, int16_t * obuf, double wet,
    double s0, double out, double b1, double b0, double s1, double t1,
    double a2, int len, double t0, double in, const int16_t * ibuf,
    int disabled, double b2)
{
  IACA_START for (int i = 0; i < len; i++)
    {
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
