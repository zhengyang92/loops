#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int n, float (*out)[38][64], float (*in)[32][2], int len)
{
  for (n = 0; n < len; n++)
    {
      out[0][n][i] = in[i][n][0];
      out[1][n][i] = in[i][n][1];
    }
}
