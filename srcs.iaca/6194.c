#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int32_t int32_t;

int
fn (int32_t * block, uint16_t * dst, int i, int stride)
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = block[0 + 4 * i] + block[2 + 4 * i];
      const int z1 = block[0 + 4 * i] - block[2 + 4 * i];
      const int z2 = (block[1 + 4 * i] >> 1) - block[3 + 4 * i];
      const int z3 = block[1 + 4 * i] + (block[3 + 4 * i] >> 1);
      dst[i + 0 * stride] =
	av_clip_uintp2_c (dst[i + 0 * stride] + ((z0 + z3) >> 6), 10);
      dst[i + 1 * stride] =
	av_clip_uintp2_c (dst[i + 1 * stride] + ((z1 + z2) >> 6), 10);
      dst[i + 2 * stride] =
	av_clip_uintp2_c (dst[i + 2 * stride] + ((z1 - z2) >> 6), 10);
      dst[i + 3 * stride] =
	av_clip_uintp2_c (dst[i + 3 * stride] + ((z0 - z3) >> 6), 10);
}}
