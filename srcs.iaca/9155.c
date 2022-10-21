#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int lf_buf, int i, int lf_idx, float (*coef)[2], float **samples)
{
  for (i = 0; i < 256; i++)
     { IACA_START
      samples[0][i] += samples[lf_buf][i] * coef[lf_idx][0];
      samples[1][i] += samples[lf_buf][i] * coef[lf_idx][1];
     } IACA_END
}
