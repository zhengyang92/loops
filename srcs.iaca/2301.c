#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;

int
fn (int32_t * block, uint16_t * dst, int i, int stride)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      const unsigned z0 = block[0 + 4 * i] + (unsigned) block[2 + 4 * i];
      const unsigned z1 = block[0 + 4 * i] - (unsigned) block[2 + 4 * i];
      const unsigned z2 =
	(block[1 + 4 * i] >> 1) - (unsigned) block[3 + 4 * i];
      const unsigned z3 =
	block[1 + 4 * i] + (unsigned) (block[3 + 4 * i] >> 1);
      dst[i + 0 * stride] =
	av_clip_uintp2_c (dst[i + 0 * stride] + ((int) (z0 + z3) >> 6), 9);
      dst[i + 1 * stride] =
	av_clip_uintp2_c (dst[i + 1 * stride] + ((int) (z1 + z2) >> 6), 9);
      dst[i + 2 * stride] =
	av_clip_uintp2_c (dst[i + 2 * stride] + ((int) (z1 - z2) >> 6), 9);
      dst[i + 3 * stride] =
	av_clip_uintp2_c (dst[i + 3 * stride] + ((int) (z0 - z3) >> 6), 9);
} IACA_END }
