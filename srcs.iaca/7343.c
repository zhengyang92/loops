#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (double a1, int i, int *clippings, double dry, double i2, double wet,
    double o2, double out, const int32_t * ibuf, double a2, double b1,
    int len, double b0, double o1, double i1, int32_t * obuf, int disabled,
    double b2)
{
  for (i = 0; i + 1 < len; i++)
    {
      o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
      i2 = ibuf[i];
      out = o2 * wet + i2 * dry;
      if (disabled)
	{
	  obuf[i] = i2;
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
      i++;
      o1 = i1 * b2 + i2 * b1 + ibuf[i] * b0 + o1 * a2 + o2 * a1;
      i1 = ibuf[i];
      out = o1 * wet + i1 * dry;
      if (disabled)
	{
	  obuf[i] = i1;
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
