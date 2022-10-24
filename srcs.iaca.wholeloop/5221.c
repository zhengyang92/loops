#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, const uint8_t * cm, int srcStride,
    const uint8_t * src, const int C2, const int C1, uint8_t * dst)
{
  const int w = 8;
  IACA_START for (i = 0; i < w; i++)
    {
      const int srcA = src[-1 * srcStride];
      const int src0 = src[0 * srcStride];
      const int src1 = src[1 * srcStride];
      const int src2 = src[2 * srcStride];
      const int src3 = src[3 * srcStride];
      const int src4 = src[4 * srcStride];
      const int src5 = src[5 * srcStride];
      const int src6 = src[6 * srcStride];
      const int src7 = src[7 * srcStride];
      const int src8 = src[8 * srcStride];
      const int src9 = src[9 * srcStride];
      dst[0 * dstStride] =
	(((dst[0 * dstStride]) +
	  cm[(-(srcA + src2) + src0 * C1 + src1 * C2 + 8) >> 4] + 1) >> 1);
      dst[1 * dstStride] =
	(((dst[1 * dstStride]) +
	  cm[(-(src0 + src3) + src1 * C1 + src2 * C2 + 8) >> 4] + 1) >> 1);
      dst[2 * dstStride] =
	(((dst[2 * dstStride]) +
	  cm[(-(src1 + src4) + src2 * C1 + src3 * C2 + 8) >> 4] + 1) >> 1);
      dst[3 * dstStride] =
	(((dst[3 * dstStride]) +
	  cm[(-(src2 + src5) + src3 * C1 + src4 * C2 + 8) >> 4] + 1) >> 1);
      dst[4 * dstStride] =
	(((dst[4 * dstStride]) +
	  cm[(-(src3 + src6) + src4 * C1 + src5 * C2 + 8) >> 4] + 1) >> 1);
      dst[5 * dstStride] =
	(((dst[5 * dstStride]) +
	  cm[(-(src4 + src7) + src5 * C1 + src6 * C2 + 8) >> 4] + 1) >> 1);
      dst[6 * dstStride] =
	(((dst[6 * dstStride]) +
	  cm[(-(src5 + src8) + src6 * C1 + src7 * C2 + 8) >> 4] + 1) >> 1);
      dst[7 * dstStride] =
	(((dst[7 * dstStride]) +
	  cm[(-(src6 + src9) + src7 * C1 + src8 * C2 + 8) >> 4] + 1) >> 1);
      dst++;
      src++;
}IACA_END}