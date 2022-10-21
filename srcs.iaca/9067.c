#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float (*X_low)[40][2], float (*X)[38][64], const int i_Temp, int i,
    int k)
{
  for (i = i_Temp; i < 38; i++)
     { IACA_START
      X[0][i][k] = X_low[k][i + 2][0];
      X[1][i][k] = X_low[k][i + 2][1];
     } IACA_END
}
