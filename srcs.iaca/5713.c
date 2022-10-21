#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*X)[38][64], const int i_Temp, const float (*Y0)[64][2], int i,
    int k)
{
  const int i_f = 32;
  for (i = 0; i < i_Temp; i++)
     { IACA_START
      X[0][i][k] = Y0[i + i_f][k][0];
      X[1][i][k] = Y0[i + i_f][k][1];
     } IACA_END
}
