#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (double a1, int *clippings, double dry, int16_t * obuf, double s3,
    double s4, double s2, double out, double wet, double a2, double s1,
    int len, double b1, const int16_t * ibuf, double in, double b0,
    int disabled, double b2)
{
  for (int i = 0; i < len; i++)
    {
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
