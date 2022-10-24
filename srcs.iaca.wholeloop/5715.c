#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*X)[38][64], const int i_Temp, int i, const float (*Y1)[64][2],
    int k)
{
  const int i_f = 32;
  IACA_START for (i = i_Temp; i < i_f; i++)
    {
      X[0][i][k] = Y1[i][k][0];
      X[1][i][k] = Y1[i][k][1];
     } IACA_END
}
