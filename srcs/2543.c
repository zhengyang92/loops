#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int o_8[4], int i, int e_8[4], int16_t * coeffs, int add)
{
  int shift = 7;
  for (i = 0; i < 4; i++)
    {
      (coeffs[i * 1]) = av_clip_int16_c (((e_8[i] + o_8[i]) + add) >> shift);
      (coeffs[(7 - i) * 1]) =
	av_clip_int16_c (((e_8[i] - o_8[i]) + add) >> shift);
    }
}
