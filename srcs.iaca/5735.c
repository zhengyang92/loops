#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float surround_mix, float center_mix, float front_mix, int len,
    float v1, float **samples, float v0)
{
  for (i = 0; i < len; i++)
     { IACA_START
      v0 =
	samples[0][i] * front_mix + samples[1][i] * center_mix +
	samples[3][i] * surround_mix;
      v1 =
	samples[1][i] * center_mix + samples[2][i] * front_mix +
	samples[4][i] * surround_mix;
      samples[0][i] = v0;
      samples[1][i] = v1;
     } IACA_END
}
