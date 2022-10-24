#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexInt32
{
  int32_t re, im;
} AVComplexInt32;
typedef AVComplexInt32 TXComplex;
typedef int32_t TXSample;

int
fn (const int len2, TXComplex * z, TXComplex tmp, TXComplex * exp,
    TXSample * src, const int *sub_map, const int len3)
{
  IACA_START for (int i = 0; i < len2; i++)
    {
      const int k = 2 * i;
      const int idx = sub_map[i];
      if (k < len2)
	{
	  tmp.re =
	    ((int32_t)
	     ((-src[len2 + k]) + (unsigned) (src[1 * len2 - 1 - k]) +
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
	     ((-src[len2 + k]) + (unsigned) (-src[5 * len2 - 1 - k]) +
	      32) >> 6);
	  tmp.im =
	    ((int32_t)
	     ((src[-len2 + k]) + (unsigned) (-src[1 * len3 - 1 - k]) +
	      32) >> 6);
	}
      do
	{
	  int64_t accu;
	  (accu) = (int64_t) (exp[i].re) * (tmp.re);
	  (accu) -= (int64_t) (exp[i].im) * (tmp.im);
	  (z[idx].im) = (int) (((accu) + 0x40000000) >> 31);
	  (accu) = (int64_t) (exp[i].im) * (tmp.re);
	  (accu) += (int64_t) (exp[i].re) * (tmp.im);
	  (z[idx].re) = (int) (((accu) + 0x40000000) >> 31);
	}
      while (0);
     } IACA_END
}
