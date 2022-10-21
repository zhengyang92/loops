#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*in)[32][2], float (*out)[38][64], int i, int n)
{
  for (i = 0; i < 12; i++)
     { IACA_START
      out[0][n][0] += in[i][n][0];
      out[1][n][0] += in[i][n][1];
     } IACA_END
}
