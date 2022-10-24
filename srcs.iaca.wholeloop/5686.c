#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*in)[32][2], float (*out)[38][64], int i, int n)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      out[0][n][2] += in[20 + i][n][0];
      out[1][n][2] += in[20 + i][n][1];
      out[0][n][3] += in[24 + i][n][0];
      out[1][n][3] += in[24 + i][n][1];
      out[0][n][4] += in[28 + i][n][0];
      out[1][n][4] += in[28 + i][n][1];
     } IACA_END
}
