#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int bias, int i, ptrdiff_t stride, int h, const int D, const int A,
    const int B, const int C, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < h; i++)
     { IACA_START
      dst[0] =
	(((dst[0]) +
	  (((A * src[0] + B * src[1] + C * src[stride + 0] +
	     D * src[stride + 1] + bias)) >> 6) + 1) >> 1);
      dst[1] =
	(((dst[1]) +
	  (((A * src[1] + B * src[2] + C * src[stride + 1] +
	     D * src[stride + 2] + bias)) >> 6) + 1) >> 1);
      dst[2] =
	(((dst[2]) +
	  (((A * src[2] + B * src[3] + C * src[stride + 2] +
	     D * src[stride + 3] + bias)) >> 6) + 1) >> 1);
      dst[3] =
	(((dst[3]) +
	  (((A * src[3] + B * src[4] + C * src[stride + 3] +
	     D * src[stride + 4] + bias)) >> 6) + 1) >> 1);
      dst += stride;
      src += stride;
     } IACA_END
}
