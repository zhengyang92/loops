#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int sl, int i, float (*coef)[2], int sr, float **samples)
{
  for (i = 0; i < 256; i++)
     { IACA_START
      samples[0][i] +=
	samples[sl][i] * coef[2][0] + samples[sr][i] * coef[2 + 1][0];
      samples[1][i] +=
	samples[sl][i] * coef[2][1] + samples[sr][i] * coef[2 + 1][1];
     } IACA_END
}
