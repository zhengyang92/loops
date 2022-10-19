#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexInt32
{
  int32_t re, im;
} AVComplexInt32;
typedef int32_t TXSample;
typedef AVComplexInt32 TXComplex;

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
	  tmp.re =
	    ((int32_t)
	     ((-src[len4 + k]) + (unsigned) (src[1 * len4 - 1 - k]) +
	      32) >> 6);
	  tmp.im =
	    ((int32_t)
	     ((-src[len3 + k]) + (unsigned) (-src[1 * len3 - 1 - k]) +
	      32) >> 6);
	}
      else
	{
	  tmp.re =
	    ((int32_t)
	     ((-src[len4 + k]) + (unsigned) (-src[5 * len4 - 1 - k]) +
	      32) >> 6);
	  tmp.im =
	    ((int32_t)
	     ((src[-len4 + k]) + (unsigned) (-src[1 * len3 - 1 - k]) +
	      32) >> 6);
	}
      do
	{
	  int64_t accu;
	  (accu) = (int64_t) (exp[k >> 1].re) * (tmp.re);
	  (accu) -= (int64_t) (exp[k >> 1].im) * (tmp.im);
	  (fft15in[j].im) = (int) (((accu) + 0x40000000) >> 31);
	  (accu) = (int64_t) (exp[k >> 1].im) * (tmp.re);
	  (accu) += (int64_t) (exp[k >> 1].re) * (tmp.im);
	  (fft15in[j].re) = (int) (((accu) + 0x40000000) >> 31);
	}
      while (0);
    }
}
