#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*in)[32][2], float (*out)[38][64], int i, int n)
{
  for (i = 0; i < 8; i++)
    {
      out[0][n][1] += in[12 + i][n][0];
      out[1][n][1] += in[12 + i][n][1];
    }
}
