#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*in)[32][2], float (*out)[38][64], int len, int n)
{
  for (n = 0; n < len; n++)
     { IACA_START
      out[0][n][0] =
	in[0][n][0] + in[1][n][0] + in[2][n][0] + in[3][n][0] + in[4][n][0] +
	in[5][n][0];
      out[1][n][0] =
	in[0][n][1] + in[1][n][1] + in[2][n][1] + in[3][n][1] + in[4][n][1] +
	in[5][n][1];
      out[0][n][1] = in[6][n][0] + in[7][n][0];
      out[1][n][1] = in[6][n][1] + in[7][n][1];
      out[0][n][2] = in[8][n][0] + in[9][n][0];
      out[1][n][2] = in[8][n][1] + in[9][n][1];
     } IACA_END
}
