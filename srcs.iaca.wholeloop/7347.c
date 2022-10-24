#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * obuf, double a1, int *clippings, double dry, double w2,
    double wet, const int32_t * ibuf, double out, double a2, double b1,
    int len, double b0, double w1, double in, double w0, int disabled,
    double b2)
{
  IACA_START for (int i = 0; i < len; i++)
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
