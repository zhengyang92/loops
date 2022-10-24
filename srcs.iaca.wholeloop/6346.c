#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int o_32[16], int e_32[16], int16_t * coeffs, int add)
{
  int shift = 7;
  IACA_START for (i = 0; i < 16; i++)
    {
      (coeffs[i * 1]) =
	av_clip_int16_c (((e_32[i] + o_32[i]) + add) >> shift);
      (coeffs[(31 - i) * 1]) =
	av_clip_int16_c (((e_32[i] - o_32[i]) + add) >> shift);
     } IACA_END
}
