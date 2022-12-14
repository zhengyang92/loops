#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int lf_buf, int lf_idx, float (*coef)[2], float **samples)
{
  IACA_START for (i = 0; i < 256; i++)
    {
      samples[0][i] += samples[lf_buf][i] * coef[lf_idx][0];
      samples[1][i] += samples[lf_buf][i] * coef[lf_idx][1];
     } IACA_END
}
