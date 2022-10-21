#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (double *param, int i, int64_t * filter, int filterSize, int xx, int j,
    int srcW, const int64_t fone, int64_t xDstInSrc, int xInc, int dstW,
    int flags)
{
  for (j = 0; j < filterSize; j++)
     { IACA_START
      int64_t d =
	(((((int64_t) xx << 17) - xDstInSrc) >=
	  0 ? (((int64_t) xx << 17) -
	       xDstInSrc) : (-(((int64_t) xx << 17) - xDstInSrc)))) << 13;
      double floatd;
      int64_t coeff;
      if (xInc > 1 << 16)
	d = d * dstW / srcW;
      floatd = d * (1.0 / (1 << 30));
      if (flags & 4)
	{
	  int64_t B = (param[0] != 123456 ? param[0] : 0) * (1 << 24);
	  int64_t C = (param[1] != 123456 ? param[1] : 0.6) * (1 << 24);
	  if (d >= 1LL << 31)
	    {
	      coeff = 0.0;
	    }
	  else
	    {
	      int64_t dd = (d * d) >> 30;
	      int64_t ddd = (dd * d) >> 30;
	      if (d < 1LL << 30)
		coeff =
		  (12 * (1 << 24) - 9 * B - 6 * C) * ddd + (-18 * (1 << 24) +
							    12 * B +
							    6 * C) * dd +
		  (6 * (1 << 24) - 2 * B) * (1 << 30);
	      else
		coeff =
		  (-B - 6 * C) * ddd + (6 * B + 30 * C) * dd + (-12 * B -
								48 * C) * d +
		  (8 * B + 24 * C) * (1 << 30);
	    }
	  coeff *= fone >> (30 + 24);
	}
      else if (flags & 8)
	{
	  double A = param[0] != 123456 ? param[0] : 1.0;
	  double c;
	  if (floatd < 1.0)
	    c = cos (floatd * 3.14159265358979323846);
	  else
	    c = -1.0;
	  if (c < 0.0)
	    c = -pow (-c, A);
	  else
	    c = pow (c, A);
	  coeff = (c * 0.5 + 0.5) * fone;
	}
      else if (flags & 0x20)
	{
	  int64_t d2 = d - (1 << 29);
	  if (d2 * xInc < -(1LL << (29 + 16)))
	    coeff = 1.0 * (1LL << (30 + 16));
	  else if (d2 * xInc < (1LL << (29 + 16)))
	    coeff = -d2 * xInc + (1LL << (29 + 16));
	  else
	    coeff = 0.0;
	  coeff *= fone >> (30 + 16);
	}
      else if (flags & 0x80)
	{
	  double p = param[0] != 123456 ? param[0] : 3.0;
	  coeff = (pow (2.0, -p * floatd * floatd)) * fone;
	}
      else if (flags & 0x100)
	{
	  coeff =
	    (d ? sin (floatd * 3.14159265358979323846) /
	     (floatd * 3.14159265358979323846) : 1.0) * fone;
	}
      else if (flags & 0x200)
	{
	  double p = param[0] != 123456 ? param[0] : 3.0;
	  coeff =
	    (d ? sin (floatd * 3.14159265358979323846) *
	     sin (floatd * 3.14159265358979323846 / p) / (floatd * floatd *
							  3.14159265358979323846
							  *
							  3.14159265358979323846
							  / p) : 1.0) * fone;
	  if (floatd > p)
	    coeff = 0;
	}
      else if (flags & 2)
	{
	  coeff = (1 << 30) - d;
	  if (coeff < 0)
	    coeff = 0;
	  coeff *= fone >> 30;
	}
      else if (flags & 0x400)
	{
	  double p = -2.196152422706632;
	  coeff = getSplineCoeff (1.0, 0.0, p, -p - 1.0, floatd) * fone;
	}
      else
	{
	  coeff = 0.0;
	  ((void) (0));
	} filter[i * filterSize + j] = coeff;
      xx++;
} IACA_END }
