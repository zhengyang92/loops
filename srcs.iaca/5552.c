#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;
typedef float TXSample;
typedef AVComplexFloat TXComplex;

int
fn (TXComplex tmp, const int len4, TXComplex * exp, TXSample * src,
    TXComplex fft9in[9], const int *in_map, const int len3)
{
  int i = 0;
  for (int j = 0; j < 9; j++)
     { IACA_START
      const int k = in_map[i * 9 + j];
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
	  (fft9in[j].im) =
	    (tmp.re) * (exp[k >> 1].re) - (tmp.im) * (exp[k >> 1].im);
	  (fft9in[j].re) =
	    (tmp.re) * (exp[k >> 1].im) + (tmp.im) * (exp[k >> 1].re);
	}
      while (0);
     } IACA_END
}
