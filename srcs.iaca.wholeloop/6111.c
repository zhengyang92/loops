#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, uint16_t * src, const int D, const int A,
    const int B, const int C, uint16_t * dst)
{
  IACA_START for (i = 0; i < h; i++)
    {
      dst[0] =
	((((A * src[0] + B * src[1] + C * src[stride + 0] +
	    D * src[stride + 1])) + 32) >> 6);
      dst[1] =
	((((A * src[1] + B * src[2] + C * src[stride + 1] +
	    D * src[stride + 2])) + 32) >> 6);
      dst += stride;
      src += stride;
     } IACA_END
}
