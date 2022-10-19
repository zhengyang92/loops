#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int i, ptrdiff_t stride, int h, uint16_t * src, const int D, const int A,
    const int B, const int C, uint16_t * dst)
{
  for (i = 0; i < h; i++)
    {
      dst[0] =
	((((A * src[0] + B * src[1] + C * src[stride + 0] +
	    D * src[stride + 1])) + 32) >> 6);
      dst += stride;
      src += stride;
    }
}
