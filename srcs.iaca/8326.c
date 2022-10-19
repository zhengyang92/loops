#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double a1, int *clippings, double dry, double wet, double s3, double s2,
    const float *ibuf, float *obuf, double a2, double s4, int len, double b0,
    double b1, double in, double out, double s1, int disabled, double b2)
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
      else if (0 && out < -1.)
	{
	  (*clippings)++;
	  obuf[i] = -1.;
	}
      else if (0 && out > 1.)
	{
	  (*clippings)++;
	  obuf[i] = 1.;
	}
      else
	{
	  obuf[i] = out;
	}
    }
}
