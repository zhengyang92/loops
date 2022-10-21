#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, const uint8_t * src, int srcStride,
    const uint8_t * cm, uint8_t * dst)
{
  const int w = 4;
  for (i = 0; i < w; i++)
     { IACA_START
      const int srcB = src[-2 * srcStride];
      const int srcA = src[-1 * srcStride];
      const int src0 = src[0 * srcStride];
      const int src1 = src[1 * srcStride];
      const int src2 = src[2 * srcStride];
      const int src3 = src[3 * srcStride];
      const int src4 = src[4 * srcStride];
      const int src5 = src[5 * srcStride];
      const int src6 = src[6 * srcStride];
      dst[0 * dstStride] =
	(((dst[0 * dstStride]) +
	  cm[(((src0 + src1) * 20 - (srcA + src2) * 5 + (srcB + src3)) +
	      16) >> 5] + 1) >> 1);
      dst[1 * dstStride] =
	(((dst[1 * dstStride]) +
	  cm[(((src1 + src2) * 20 - (src0 + src3) * 5 + (srcA + src4)) +
	      16) >> 5] + 1) >> 1);
      dst[2 * dstStride] =
	(((dst[2 * dstStride]) +
	  cm[(((src2 + src3) * 20 - (src1 + src4) * 5 + (src0 + src5)) +
	      16) >> 5] + 1) >> 1);
      dst[3 * dstStride] =
	(((dst[3 * dstStride]) +
	  cm[(((src3 + src4) * 20 - (src2 + src5) * 5 + (src1 + src6)) +
	      16) >> 5] + 1) >> 1);
      dst++;
      src++;
} IACA_END }
