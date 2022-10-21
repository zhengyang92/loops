#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int16_t temp[64], ptrdiff_t linesize, int i, uint8_t * dest)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      const int a1 = ((&temp[8 * i]))[1] + ((&temp[8 * i]))[7];
      const int a7 = ((&temp[8 * i]))[1] - ((&temp[8 * i]))[7];
      const int a5 = ((&temp[8 * i]))[5] + ((&temp[8 * i]))[3];
      const int a3 = ((&temp[8 * i]))[5] - ((&temp[8 * i]))[3];
      const int a2 = ((&temp[8 * i]))[2] + ((&temp[8 * i]))[6];
      const int a6 = (181 * (((&temp[8 * i]))[2] - ((&temp[8 * i]))[6])) >> 8;
      const int a0 = ((&temp[8 * i]))[0] + ((&temp[8 * i]))[4];
      const int a4 = ((&temp[8 * i]))[0] - ((&temp[8 * i]))[4];
      const int b0 = (((669 - 196) * a7 - 196 * a3) >> 9) + a1 + a5;
      const int b1 =
	(((669 - 196) * a7 - 196 * a3) >> 9) + ((181 * (a1 - a5)) >> 8);
      const int b2 =
	(((277 + 196) * a3 + 196 * a7) >> 9) + ((181 * (a1 - a5)) >> 8);
      const int b3 = ((277 + 196) * a3 + 196 * a7) >> 9;
      ((&dest[i * linesize]))[0] = av_clip_uint8_c ((a0 + a2 + a6 + b0) >> 4);
      ((&dest[i * linesize]))[1] = av_clip_uint8_c ((a4 + a6 + b1) >> 4);
      ((&dest[i * linesize]))[2] = av_clip_uint8_c ((a4 - a6 + b2) >> 4);
      ((&dest[i * linesize]))[3] = av_clip_uint8_c ((a0 - a2 - a6 + b3) >> 4);
      ((&dest[i * linesize]))[4] = av_clip_uint8_c ((a0 - a2 - a6 - b3) >> 4);
      ((&dest[i * linesize]))[5] = av_clip_uint8_c ((a4 - a6 - b2) >> 4);
      ((&dest[i * linesize]))[6] = av_clip_uint8_c ((a4 + a6 - b1) >> 4);
      ((&dest[i * linesize]))[7] = av_clip_uint8_c ((a0 + a2 + a6 - b0) >> 4);
} IACA_END }
