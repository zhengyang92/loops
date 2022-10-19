#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;
typedef AVComplexFloat TXComplex;
typedef float TXSample;

int
fn (TXComplex tmp, TXComplex fft5in[5], const int len4, TXComplex * exp,
    TXSample * src, const int *in_map, const int len3)
{
  int i = 0;
  for (int j = 0; j < 5; j++)
    {
      const int k = in_map[i * 5 + j];
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
	  (fft5in[j].im) =
	    (tmp.re) * (exp[k >> 1].re) - (tmp.im) * (exp[k >> 1].im);
	  (fft5in[j].re) =
	    (tmp.re) * (exp[k >> 1].im) + (tmp.im) * (exp[k >> 1].re);
	}
      while (0);
    }
}
