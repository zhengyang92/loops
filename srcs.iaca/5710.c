#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float (*X_low)[40][2], int buf_idx, const float (*W)[32][32][2],
    int k)
{
  const int i_f = 32;
  const int t_HFGen = 8;
  for (i = t_HFGen; i < i_f + t_HFGen; i++)
     { IACA_START
      X_low[k][i][0] = W[buf_idx][i - t_HFGen][k][0];
      X_low[k][i][1] = W[buf_idx][i - t_HFGen][k][1];
     } IACA_END
}
