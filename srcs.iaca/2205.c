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
     { IACA_START
      dst[0] =
	((((A * src[0] + B * src[1] + C * src[stride + 0] +
	    D * src[stride + 1])) + 32) >> 6);
      dst[1] =
	((((A * src[1] + B * src[2] + C * src[stride + 1] +
	    D * src[stride + 2])) + 32) >> 6);
      dst[2] =
	((((A * src[2] + B * src[3] + C * src[stride + 2] +
	    D * src[stride + 3])) + 32) >> 6);
      dst[3] =
	((((A * src[3] + B * src[4] + C * src[stride + 3] +
	    D * src[stride + 4])) + 32) >> 6);
      dst += stride;
      src += stride;
     } IACA_END
}
