#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int o_16[8], int16_t * src, int add, int e_16[8])
{
  int shift = 7;
  for (i = 0; i < 8; i++)
    {
      (src[i * 16]) = av_clip_int16_c (((e_16[i] + o_16[i]) + add) >> shift);
      (src[(15 - i) * 16]) =
	av_clip_int16_c (((e_16[i] - o_16[i]) + add) >> shift);
    }
}
