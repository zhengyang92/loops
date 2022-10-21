#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (double a1, int *clippings, double dry, double wet, const int32_t * ibuf,
    double s2, double out, double s3, double b1, double s1, double b0,
    int len, double a2, double in, double s4, int32_t * obuf, int disabled,
    double b2)
{
  for (int i = 0; i < len; i++)
     { IACA_START
      double t1, t2, t3, t4;
      in = ibuf[i] + s1;
      t1 = in * a1 + s2;
      t2 = in * a2;
      t3 = in * b1 + s4;
      t4 = in * b2;
      out = b0 * in + s3;
      out = out * wet + in * dry;
      s1 = t1;
      s2 = t2;
      s3 = t3;
      s4 = t4;
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
