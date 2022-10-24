#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*X)[38][64], const float (*X_low)[40][2], const int i_Temp, int i,
    int k)
{
  IACA_START for (i = 0; i < i_Temp; i++)
    {
      X[0][i][k] = X_low[k][i + 2][0];
      X[1][i][k] = X_low[k][i + 2][1];
     } IACA_END
}
