#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int i, int dstStride, const int pad, int tmpStride, const uint8_t * cm,
    uint8_t * dst, int16_t * tmp)
{
  const int w = 8;
  for (i = 0; i < w; i++)
    {
      const int tmpB = tmp[-2 * tmpStride] - pad;
      const int tmpA = tmp[-1 * tmpStride] - pad;
      const int tmp0 = tmp[0 * tmpStride] - pad;
      const int tmp1 = tmp[1 * tmpStride] - pad;
      const int tmp2 = tmp[2 * tmpStride] - pad;
      const int tmp3 = tmp[3 * tmpStride] - pad;
      const int tmp4 = tmp[4 * tmpStride] - pad;
      const int tmp5 = tmp[5 * tmpStride] - pad;
      const int tmp6 = tmp[6 * tmpStride] - pad;
      const int tmp7 = tmp[7 * tmpStride] - pad;
      const int tmp8 = tmp[8 * tmpStride] - pad;
      const int tmp9 = tmp[9 * tmpStride] - pad;
      const int tmp10 = tmp[10 * tmpStride] - pad;
      dst[0 * dstStride] =
	cm[(((tmp0 + tmp1) * 20 - (tmpA + tmp2) * 5 + (tmpB + tmp3)) +
	    512) >> 10];
      dst[1 * dstStride] =
	cm[(((tmp1 + tmp2) * 20 - (tmp0 + tmp3) * 5 + (tmpA + tmp4)) +
	    512) >> 10];
      dst[2 * dstStride] =
	cm[(((tmp2 + tmp3) * 20 - (tmp1 + tmp4) * 5 + (tmp0 + tmp5)) +
	    512) >> 10];
      dst[3 * dstStride] =
	cm[(((tmp3 + tmp4) * 20 - (tmp2 + tmp5) * 5 + (tmp1 + tmp6)) +
	    512) >> 10];
      dst[4 * dstStride] =
	cm[(((tmp4 + tmp5) * 20 - (tmp3 + tmp6) * 5 + (tmp2 + tmp7)) +
	    512) >> 10];
      dst[5 * dstStride] =
	cm[(((tmp5 + tmp6) * 20 - (tmp4 + tmp7) * 5 + (tmp3 + tmp8)) +
	    512) >> 10];
      dst[6 * dstStride] =
	cm[(((tmp6 + tmp7) * 20 - (tmp5 + tmp8) * 5 + (tmp4 + tmp9)) +
	    512) >> 10];
      dst[7 * dstStride] =
	cm[(((tmp7 + tmp8) * 20 - (tmp6 + tmp9) * 5 + (tmp5 + tmp10)) +
	    512) >> 10];
      dst++;
      tmp++;
}}
