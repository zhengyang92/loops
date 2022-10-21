#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, int dstStride, int srcStride, uint16_t * dst, const uint16_t * src)
{
  const int w = 8;
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
      const int src7 = src[7 * srcStride];
      const int src8 = src[8 * srcStride];
      const int src9 = src[9 * srcStride];
      const int src10 = src[10 * srcStride];
      dst[0 * dstStride] =
	(((dst[0 * dstStride]) +
	  av_clip_uintp2_c ((((src0 + src1) * 20 - (srcA + src2) * 5 +
			      (srcB + src3)) + 16) >> 5, 10) + 1) >> 1);
      dst[1 * dstStride] =
	(((dst[1 * dstStride]) +
	  av_clip_uintp2_c ((((src1 + src2) * 20 - (src0 + src3) * 5 +
			      (srcA + src4)) + 16) >> 5, 10) + 1) >> 1);
      dst[2 * dstStride] =
	(((dst[2 * dstStride]) +
	  av_clip_uintp2_c ((((src2 + src3) * 20 - (src1 + src4) * 5 +
			      (src0 + src5)) + 16) >> 5, 10) + 1) >> 1);
      dst[3 * dstStride] =
	(((dst[3 * dstStride]) +
	  av_clip_uintp2_c ((((src3 + src4) * 20 - (src2 + src5) * 5 +
			      (src1 + src6)) + 16) >> 5, 10) + 1) >> 1);
      dst[4 * dstStride] =
	(((dst[4 * dstStride]) +
	  av_clip_uintp2_c ((((src4 + src5) * 20 - (src3 + src6) * 5 +
			      (src2 + src7)) + 16) >> 5, 10) + 1) >> 1);
      dst[5 * dstStride] =
	(((dst[5 * dstStride]) +
	  av_clip_uintp2_c ((((src5 + src6) * 20 - (src4 + src7) * 5 +
			      (src3 + src8)) + 16) >> 5, 10) + 1) >> 1);
      dst[6 * dstStride] =
	(((dst[6 * dstStride]) +
	  av_clip_uintp2_c ((((src6 + src7) * 20 - (src5 + src8) * 5 +
			      (src4 + src9)) + 16) >> 5, 10) + 1) >> 1);
      dst[7 * dstStride] =
	(((dst[7 * dstStride]) +
	  av_clip_uintp2_c ((((src7 + src8) * 20 - (src6 + src9) * 5 +
			      (src5 + src10)) + 16) >> 5, 10) + 1) >> 1);
      dst++;
      src++;
} IACA_END }
