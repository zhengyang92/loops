#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, const int pad, int tmpStride, uint8_t * dst,
    int16_t * tmp)
{
  const int w = 2;
  for (i = 0; i < w; i++)
    {
      const int tmpB = tmp[-2 * tmpStride] - pad;
      const int tmpA = tmp[-1 * tmpStride] - pad;
      const int tmp0 = tmp[0 * tmpStride] - pad;
      const int tmp1 = tmp[1 * tmpStride] - pad;
      const int tmp2 = tmp[2 * tmpStride] - pad;
      const int tmp3 = tmp[3 * tmpStride] - pad;
      const int tmp4 = tmp[4 * tmpStride] - pad;
      dst[0 * dstStride] =
	(((dst[0 * dstStride]) +
	  av_clip_uint8_c ((((tmp0 + tmp1) * 20 - (tmpA + tmp2) * 5 +
			     (tmpB + tmp3)) + 512) >> 10) + 1) >> 1);
      dst[1 * dstStride] =
	(((dst[1 * dstStride]) +
	  av_clip_uint8_c ((((tmp1 + tmp2) * 20 - (tmp0 + tmp3) * 5 +
			     (tmpA + tmp4)) + 512) >> 10) + 1) >> 1);
      dst++;
      tmp++;
}}
