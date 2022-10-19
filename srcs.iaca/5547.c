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
fn (TXComplex tmp, TXComplex fft15in[15], const int len4, TXComplex * exp,
    TXSample * src, const int *in_map, const int len3)
{
  int i = 0;
  for (int j = 0; j < 15; j++)
    {
      const int k = in_map[i * 15 + j];
      if (k < len4)
	{
	  tmp.re = ((-src[len4 + k]) + (src[1 * len4 - 1 - k]));
	  tmp.im = ((-src[len3 + k]) + (-src[1 * len3 - 1 - k]));
	}
      else
	{
	  tmp.re = ((-src[len4 + k]) + (-src[5 * len4 - 1 - k]));
	  tmp.im = ((src[-len4 + k]) + (-src[1 * len3 - 1 - k]));
	}
      do
	{
	  (fft15in[j].im) =
	    (tmp.re) * (exp[k >> 1].re) - (tmp.im) * (exp[k >> 1].im);
	  (fft15in[j].re) =
	    (tmp.re) * (exp[k >> 1].im) + (tmp.im) * (exp[k >> 1].re);
	}
      while (0);
    }
}
