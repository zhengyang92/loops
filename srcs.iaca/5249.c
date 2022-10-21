#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float (*X_high)[2], const float (*X_low)[2], int end,
    float alpha[4], int start)
{
  for (i = start; i < end; i++)
     { IACA_START
      X_high[i][0] =
	X_low[i - 2][0] * alpha[0] - X_low[i - 2][1] * alpha[1] + X_low[i -
									1][0]
	* alpha[2] - X_low[i - 1][1] * alpha[3] + X_low[i][0];
      X_high[i][1] =
	X_low[i - 2][1] * alpha[0] + X_low[i - 2][0] * alpha[1] + X_low[i -
									1][1]
	* alpha[2] + X_low[i - 1][0] * alpha[3] + X_low[i][1];
     } IACA_END
}
