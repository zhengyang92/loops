#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int h, const int D, const int A, const int B,
    const int C, uint8_t * dst, uint8_t * src)
{
  IACA_START for (i = 0; i < h; i++)
    {
      dst[0] =
	(((dst[0]) +
	  ((((A * src[0] + B * src[1] + C * src[stride + 0] +
	      D * src[stride + 1])) + 32) >> 6) + 1) >> 1);
      dst[1] =
	(((dst[1]) +
	  ((((A * src[1] + B * src[2] + C * src[stride + 1] +
	      D * src[stride + 2])) + 32) >> 6) + 1) >> 1);
      dst[2] =
	(((dst[2]) +
	  ((((A * src[2] + B * src[3] + C * src[stride + 2] +
	      D * src[stride + 3])) + 32) >> 6) + 1) >> 1);
      dst[3] =
	(((dst[3]) +
	  ((((A * src[3] + B * src[4] + C * src[stride + 3] +
	      D * src[stride + 4])) + 32) >> 6) + 1) >> 1);
      dst[4] =
	(((dst[4]) +
	  ((((A * src[4] + B * src[5] + C * src[stride + 4] +
	      D * src[stride + 5])) + 32) >> 6) + 1) >> 1);
      dst[5] =
	(((dst[5]) +
	  ((((A * src[5] + B * src[6] + C * src[stride + 5] +
	      D * src[stride + 6])) + 32) >> 6) + 1) >> 1);
      dst[6] =
	(((dst[6]) +
	  ((((A * src[6] + B * src[7] + C * src[stride + 6] +
	      D * src[stride + 7])) + 32) >> 6) + 1) >> 1);
      dst[7] =
	(((dst[7]) +
	  ((((A * src[7] + B * src[8] + C * src[stride + 7] +
	      D * src[stride + 8])) + 32) >> 6) + 1) >> 1);
      dst += stride;
      src += stride;
     } IACA_END
}
