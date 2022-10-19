#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const int qmul, int i, int16_t * block, int dc, uint8_t * dst, int stride)
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = 13 * (block[i + 4 * 0] + block[i + 4 * 2]);
      const int z1 = 13 * (block[i + 4 * 0] - block[i + 4 * 2]);
      const int z2 = 7 * block[i + 4 * 1] - 17 * block[i + 4 * 3];
      const int z3 = 17 * block[i + 4 * 1] + 7 * block[i + 4 * 3];
      const int rr = (dc + 0x80000);
      dst[i + stride * 0] =
	av_clip_uint8_c (dst[i + stride * 0] + ((z0 + z3) * qmul + rr >> 20));
      dst[i + stride * 1] =
	av_clip_uint8_c (dst[i + stride * 1] + ((z1 + z2) * qmul + rr >> 20));
      dst[i + stride * 2] =
	av_clip_uint8_c (dst[i + stride * 2] + ((z1 - z2) * qmul + rr >> 20));
      dst[i + stride * 3] =
	av_clip_uint8_c (dst[i + stride * 3] + ((z0 - z3) * qmul + rr >> 20));
}}
