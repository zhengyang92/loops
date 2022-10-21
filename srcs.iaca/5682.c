#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*in)[44][2], int j, float (*L)[38][64], int i)
{
  for (j = 0; j < 38; j++)
     { IACA_START
      in[i][j + 6][0] = L[0][j][i];
      in[i][j + 6][1] = L[1][j][i];
     } IACA_END
}
