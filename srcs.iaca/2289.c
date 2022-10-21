#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * block, uint8_t * dst, int i, int stride)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      const unsigned a0 = block[0 + i * 8] + (unsigned) block[4 + i * 8];
      const unsigned a2 = block[0 + i * 8] - (unsigned) block[4 + i * 8];
      const unsigned a4 =
	(block[2 + i * 8] >> 1) - (unsigned) block[6 + i * 8];
      const unsigned a6 =
	(block[6 + i * 8] >> 1) + (unsigned) block[2 + i * 8];
      const unsigned b0 = a0 + a6;
      const unsigned b2 = a2 + a4;
      const unsigned b4 = a2 - a4;
      const unsigned b6 = a0 - a6;
      const int a1 =
	-(unsigned) block[3 + i * 8] + block[5 + i * 8] - block[7 + i * 8] -
	(block[7 + i * 8] >> 1);
      const int a3 =
	(unsigned) block[1 + i * 8] + block[7 + i * 8] - block[3 + i * 8] -
	(block[3 + i * 8] >> 1);
      const int a5 =
	-(unsigned) block[1 + i * 8] + block[7 + i * 8] + block[5 + i * 8] +
	(block[5 + i * 8] >> 1);
      const int a7 =
	(unsigned) block[3 + i * 8] + block[5 + i * 8] + block[1 + i * 8] +
	(block[1 + i * 8] >> 1);
      const unsigned b1 = (a7 >> 2) + (unsigned) a1;
      const unsigned b3 = (unsigned) a3 + (a5 >> 2);
      const unsigned b5 = (a3 >> 2) - (unsigned) a5;
      const unsigned b7 = (unsigned) a7 - (a1 >> 2);
      dst[i + 0 * stride] =
	av_clip_uint8_c (dst[i + 0 * stride] + ((int) (b0 + b7) >> 6));
      dst[i + 1 * stride] =
	av_clip_uint8_c (dst[i + 1 * stride] + ((int) (b2 + b5) >> 6));
      dst[i + 2 * stride] =
	av_clip_uint8_c (dst[i + 2 * stride] + ((int) (b4 + b3) >> 6));
      dst[i + 3 * stride] =
	av_clip_uint8_c (dst[i + 3 * stride] + ((int) (b6 + b1) >> 6));
      dst[i + 4 * stride] =
	av_clip_uint8_c (dst[i + 4 * stride] + ((int) (b6 - b1) >> 6));
      dst[i + 5 * stride] =
	av_clip_uint8_c (dst[i + 5 * stride] + ((int) (b4 - b3) >> 6));
      dst[i + 6 * stride] =
	av_clip_uint8_c (dst[i + 6 * stride] + ((int) (b2 - b5) >> 6));
      dst[i + 7 * stride] =
	av_clip_uint8_c (dst[i + 7 * stride] + ((int) (b0 - b7) >> 6));
} IACA_END }
