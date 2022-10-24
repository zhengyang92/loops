#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float v, int r, int c, float (*coef)[2], float u, float t, int l,
    float **samples)
{
  IACA_START for (i = 0; i < 256; i++)
    {
      t = samples[c][i];
      u = samples[l][i];
      v = samples[r][i];
      samples[0][i] = t * coef[0][0] + u * coef[1][0] + v * coef[2][0];
      samples[1][i] = t * coef[0][1] + u * coef[1][1] + v * coef[2][1];
     } IACA_END
}
