#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * block, uint8_t * dst, int i, int stride)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      const int z0 = block[0 + 4 * i] + block[2 + 4 * i];
      const int z1 = block[0 + 4 * i] - block[2 + 4 * i];
      const int z2 = (block[1 + 4 * i] >> 1) - block[3 + 4 * i];
      const int z3 = block[1 + 4 * i] + (block[3 + 4 * i] >> 1);
      dst[i + 0 * stride] =
	av_clip_uint8_c (dst[i + 0 * stride] + ((z0 + z3) >> 6));
      dst[i + 1 * stride] =
	av_clip_uint8_c (dst[i + 1 * stride] + ((z1 + z2) >> 6));
      dst[i + 2 * stride] =
	av_clip_uint8_c (dst[i + 2 * stride] + ((z1 - z2) >> 6));
      dst[i + 3 * stride] =
	av_clip_uint8_c (dst[i + 3 * stride] + ((z0 - z3) >> 6));
}IACA_END}
