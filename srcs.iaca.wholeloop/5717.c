#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *g_filt, const int h_SL, int m, float (*g_temp)[48],
    float (*q_temp)[48], float *q_filt, int j, const float h_smooth[5],
    const int idx1)
{
  IACA_START for (j = 0; j <= h_SL; j++)
    {
      g_filt[m] += g_temp[idx1 - j][m] * h_smooth[j];
      q_filt[m] += q_temp[idx1 - j][m] * h_smooth[j];
     } IACA_END
}
