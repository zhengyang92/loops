#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int o_32[16], int e_32[16], int16_t * src, int add)
{
  int shift = 7;
  for (i = 0; i < 16; i++)
     { IACA_START
      (src[i * 32]) = av_clip_int16_c (((e_32[i] + o_32[i]) + add) >> shift);
      (src[(31 - i) * 32]) =
	av_clip_int16_c (((e_32[i] - o_32[i]) + add) >> shift);
     } IACA_END
}
