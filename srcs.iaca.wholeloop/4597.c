#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float surround_mix, float center_mix, float front_mix, int len,
    float **samples)
{
  IACA_START for (i = 0; i < len; i++)
    {
      samples[0][i] =
	samples[0][i] * front_mix + samples[1][i] * center_mix +
	samples[2][i] * front_mix + samples[3][i] * surround_mix +
	samples[4][i] * surround_mix;
     } IACA_END
}
