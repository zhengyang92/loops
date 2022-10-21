#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * block, uint8_t * dst, int i, int stride)
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
	av_clip_uint8_c (dst[i + 0 * stride] + ((int) (z0 + z3) >> 6));
      dst[i + 1 * stride] =
	av_clip_uint8_c (dst[i + 1 * stride] + ((int) (z1 + z2) >> 6));
      dst[i + 2 * stride] =
	av_clip_uint8_c (dst[i + 2 * stride] + ((int) (z1 - z2) >> 6));
      dst[i + 3 * stride] =
	av_clip_uint8_c (dst[i + 3 * stride] + ((int) (z0 - z3) >> 6));
} IACA_END }
