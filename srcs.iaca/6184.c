#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int32_t int32_t;

int
fn (int32_t * block, uint16_t * dst, int i, int stride)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      const int a0 = block[0 + i * 8] + block[4 + i * 8];
      const int a2 = block[0 + i * 8] - block[4 + i * 8];
      const int a4 = (block[2 + i * 8] >> 1) - block[6 + i * 8];
      const int a6 = (block[6 + i * 8] >> 1) + block[2 + i * 8];
      const int b0 = a0 + a6;
      const int b2 = a2 + a4;
      const int b4 = a2 - a4;
      const int b6 = a0 - a6;
      const int a1 =
	-block[3 + i * 8] + block[5 + i * 8] - block[7 + i * 8] -
	(block[7 + i * 8] >> 1);
      const int a3 =
	block[1 + i * 8] + block[7 + i * 8] - block[3 + i * 8] -
	(block[3 + i * 8] >> 1);
      const int a5 =
	-block[1 + i * 8] + block[7 + i * 8] + block[5 + i * 8] +
	(block[5 + i * 8] >> 1);
      const int a7 =
	block[3 + i * 8] + block[5 + i * 8] + block[1 + i * 8] +
	(block[1 + i * 8] >> 1);
      const int b1 = (a7 >> 2) + a1;
      const int b3 = a3 + (a5 >> 2);
      const int b5 = (a3 >> 2) - a5;
      const int b7 = a7 - (a1 >> 2);
      dst[i + 0 * stride] =
	av_clip_uintp2_c (dst[i + 0 * stride] + ((b0 + b7) >> 6), 9);
      dst[i + 1 * stride] =
	av_clip_uintp2_c (dst[i + 1 * stride] + ((b2 + b5) >> 6), 9);
      dst[i + 2 * stride] =
	av_clip_uintp2_c (dst[i + 2 * stride] + ((b4 + b3) >> 6), 9);
      dst[i + 3 * stride] =
	av_clip_uintp2_c (dst[i + 3 * stride] + ((b6 + b1) >> 6), 9);
      dst[i + 4 * stride] =
	av_clip_uintp2_c (dst[i + 4 * stride] + ((b6 - b1) >> 6), 9);
      dst[i + 5 * stride] =
	av_clip_uintp2_c (dst[i + 5 * stride] + ((b4 - b3) >> 6), 9);
      dst[i + 6 * stride] =
	av_clip_uintp2_c (dst[i + 6 * stride] + ((b2 - b5) >> 6), 9);
      dst[i + 7 * stride] =
	av_clip_uintp2_c (dst[i + 7 * stride] + ((b0 - b7) >> 6), 9);
} IACA_END }
