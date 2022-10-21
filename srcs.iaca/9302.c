#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int tmpStride, int i, int dstStride, const int pad, int16_t * tmp,
    const uint8_t * cm, uint8_t * dst)
{
  const int w = 2;
  for (i = 0; i < w; i++)
     { IACA_START
      const int tmpB = tmp[-2 * tmpStride] - pad;
      const int tmpA = tmp[-1 * tmpStride] - pad;
      const int tmp0 = tmp[0 * tmpStride] - pad;
      const int tmp1 = tmp[1 * tmpStride] - pad;
      const int tmp2 = tmp[2 * tmpStride] - pad;
      const int tmp3 = tmp[3 * tmpStride] - pad;
      const int tmp4 = tmp[4 * tmpStride] - pad;
      dst[0 * dstStride] =
	cm[(((tmp0 + tmp1) * 20 - (tmpA + tmp2) * 5 + (tmpB + tmp3)) +
	    512) >> 10];
      dst[1 * dstStride] =
	cm[(((tmp1 + tmp2) * 20 - (tmp0 + tmp3) * 5 + (tmpA + tmp4)) +
	    512) >> 10];
      dst++;
      tmp++;
} IACA_END }
