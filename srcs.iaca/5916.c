#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int sl, int i, float v, int r, int c, float (*coef)[2], float t, float u,
    int sr, int l, float **samples)
{
  for (i = 0; i < 256; i++)
    {
      t = samples[c][i];
      u = samples[l][i];
      v = samples[r][i];
      samples[0][i] = t * coef[0][0] + u * coef[1][0] + v * coef[2][0];
      samples[1][i] = t * coef[0][1] + u * coef[1][1] + v * coef[2][1];
      samples[0][i] +=
	samples[sl][i] * coef[3][0] + samples[sr][i] * coef[3 + 1][0];
      samples[1][i] +=
	samples[sl][i] * coef[3][1] + samples[sr][i] * coef[3 + 1][1];
    }
}
