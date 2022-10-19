#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, const int qmul, int16_t * block, int dc, uint8_t * dst, int stride)
{
  for (i = 0; i < 4; i++)
    {
      const unsigned z0 = 13 * (block[i + 4 * 0] + block[i + 4 * 2]);
      const unsigned z1 = 13 * (block[i + 4 * 0] - block[i + 4 * 2]);
      const unsigned z2 = 7 * block[i + 4 * 1] - 17 * block[i + 4 * 3];
      const unsigned z3 = 17 * block[i + 4 * 1] + 7 * block[i + 4 * 3];
      const int rr = (dc + 0x80000u);
      dst[i + stride * 0] =
	av_clip_uint8_c (dst[i + stride * 0] +
			 ((int) ((z0 + z3) * qmul + rr) >> 20));
      dst[i + stride * 1] =
	av_clip_uint8_c (dst[i + stride * 1] +
			 ((int) ((z1 + z2) * qmul + rr) >> 20));
      dst[i + stride * 2] =
	av_clip_uint8_c (dst[i + stride * 2] +
			 ((int) ((z1 - z2) * qmul + rr) >> 20));
      dst[i + stride * 3] =
	av_clip_uint8_c (dst[i + stride * 3] +
			 ((int) ((z0 - z3) * qmul + rr) >> 20));
}}
