#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int32_t round, const int32_t * src1, int16_t * dst, int32_t wj,
    const int32_t * win, int32_t s0, int len, int32_t s1, int32_t i,
    const int32_t * src0, int32_t j, int32_t wi, uint8_t bits)
{
  for (i = -len, j = len - 1; i < 0; i++, j--)
     { IACA_START
      s0 = src0[i];
      s1 = src1[j];
      wi = win[i];
      wj = win[j];
      dst[i] =
	av_clip_int16_c (((((int64_t) s0 * wj - (int64_t) s1 * wi +
			    0x40000000) >> 31) + round) >> bits);
      dst[j] =
	av_clip_int16_c (((((int64_t) s0 * wi + (int64_t) s1 * wj +
			    0x40000000) >> 31) + round) >> bits);
     } IACA_END
}
