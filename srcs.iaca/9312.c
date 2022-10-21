#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int tmpStride, int i, int dstStride, const int pad, int16_t * tmp,
    const uint8_t * cm, uint8_t * dst)
{
  const int w = 4;
  for (i = 0; i < w; i++)
     { IACA_START
      const int tmpB = tmp[-2 * tmpStride] - pad;
      const int tmpA = tmp[-1 * tmpStride] - pad;
      const int tmp0 = tmp[0 * tmpStride] - pad;
      const int tmp1 = tmp[1 * tmpStride] - pad;
      const int tmp2 = tmp[2 * tmpStride] - pad;
      const int tmp3 = tmp[3 * tmpStride] - pad;
      const int tmp4 = tmp[4 * tmpStride] - pad;
      const int tmp5 = tmp[5 * tmpStride] - pad;
      const int tmp6 = tmp[6 * tmpStride] - pad;
      dst[0 * dstStride] =
	(((dst[0 * dstStride]) +
	  cm[(((tmp0 + tmp1) * 20 - (tmpA + tmp2) * 5 + (tmpB + tmp3)) +
	      512) >> 10] + 1) >> 1);
      dst[1 * dstStride] =
	(((dst[1 * dstStride]) +
	  cm[(((tmp1 + tmp2) * 20 - (tmp0 + tmp3) * 5 + (tmpA + tmp4)) +
	      512) >> 10] + 1) >> 1);
      dst[2 * dstStride] =
	(((dst[2 * dstStride]) +
	  cm[(((tmp2 + tmp3) * 20 - (tmp1 + tmp4) * 5 + (tmp0 + tmp5)) +
	      512) >> 10] + 1) >> 1);
      dst[3 * dstStride] =
	(((dst[3 * dstStride]) +
	  cm[(((tmp3 + tmp4) * 20 - (tmp2 + tmp5) * 5 + (tmp1 + tmp6)) +
	      512) >> 10] + 1) >> 1);
      dst++;
      tmp++;
} IACA_END }
