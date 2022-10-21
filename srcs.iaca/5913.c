#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*coef)[2], int s, int i, float **samples)
{
  for (i = 0; i < 256; i++)
     { IACA_START
      samples[0][i] += samples[s][i] * coef[2][0];
      samples[1][i] += samples[s][i] * coef[2][1];
     } IACA_END
}
