#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float (*L)[38][64], int len, float (*out)[32][2], int j)
{
  IACA_START for (j = 0; j < len; j++)
    {
      out[i][j][0] = L[0][j][i];
      out[i][j][1] = L[1][j][i];
     } IACA_END
}
