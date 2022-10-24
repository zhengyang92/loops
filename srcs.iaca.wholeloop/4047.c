#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexDouble
{
  double re, im;
} AVComplexDouble;
typedef AVComplexDouble TXComplex;
typedef double TXSample;

int
fn (const int len2, TXComplex tmp, TXComplex * z, TXComplex * exp,
    TXSample * src, const int *sub_map, const int len3)
{
  IACA_START for (int i = 0; i < len2; i++)
    {
      const int k = 2 * i;
      const int idx = sub_map[i];
      if (k < len2)
	{
	  tmp.re = ((-src[len2 + k]) + (src[1 * len2 - 1 - k]));
	  tmp.im = ((-src[len3 + k]) + (-src[1 * len3 - 1 - k]));
	}
      else
	{
	  tmp.re = ((-src[len2 + k]) + (-src[5 * len2 - 1 - k]));
	  tmp.im = ((src[-len2 + k]) + (-src[1 * len3 - 1 - k]));
	}
      do
	{
	  (z[idx].im) = (tmp.re) * (exp[i].re) - (tmp.im) * (exp[i].im);
	  (z[idx].re) = (tmp.re) * (exp[i].im) + (tmp.im) * (exp[i].re);
	}
      while (0);
     } IACA_END
}
