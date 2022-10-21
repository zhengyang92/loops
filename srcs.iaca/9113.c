#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, const uint8_t * src, ptrdiff_t dstStride, ptrdiff_t srcStride,
    const uint8_t * cm, uint8_t * dst)
{
  const int h = 8;
  for (i = 0; i < h; i++)
     { IACA_START
      dst[0] =
	cm[((0 * src[-2] + -7 * src[-1] + 42 * src[0] + 96 * src[1] +
	     -2 * src[2] + -1 * src[3]) + 64) >> 7];
      dst[1] =
	cm[((0 * src[-1] + -7 * src[0] + 42 * src[1] + 96 * src[2] +
	     -2 * src[3] + -1 * src[4]) + 64) >> 7];
      dst[2] =
	cm[((0 * src[0] + -7 * src[1] + 42 * src[2] + 96 * src[3] +
	     -2 * src[4] + -1 * src[5]) + 64) >> 7];
      dst[3] =
	cm[((0 * src[1] + -7 * src[2] + 42 * src[3] + 96 * src[4] +
	     -2 * src[5] + -1 * src[6]) + 64) >> 7];
      dst[4] =
	cm[((0 * src[2] + -7 * src[3] + 42 * src[4] + 96 * src[5] +
	     -2 * src[6] + -1 * src[7]) + 64) >> 7];
      dst[5] =
	cm[((0 * src[3] + -7 * src[4] + 42 * src[5] + 96 * src[6] +
	     -2 * src[7] + -1 * src[8]) + 64) >> 7];
      dst[6] =
	cm[((0 * src[4] + -7 * src[5] + 42 * src[6] + 96 * src[7] +
	     -2 * src[8] + -1 * src[9]) + 64) >> 7];
      dst[7] =
	cm[((0 * src[5] + -7 * src[6] + 42 * src[7] + 96 * src[8] +
	     -2 * src[9] + -1 * src[10]) + 64) >> 7];
      dst += dstStride;
      src += srcStride;
     } IACA_END
}
