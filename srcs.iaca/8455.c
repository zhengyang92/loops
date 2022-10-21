#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int upper, int width, int x, int u, int upper2, int height,
    const uint8_t * dp, int tpitch)
{
  int lower = 0;
  int lower2 = 0;
  for (u = ((x - 4) > (0) ? (x - 4) : (0));
       u < ((x + 5) > (width) ? (width) : (x + 5)); u++)
     { IACA_START
      if (y != 2 && dp[u - 2 * tpitch] > 19)
	upper2 = 1;
      if (dp[u - tpitch] > 19)
	upper = 1;
      if (dp[u + tpitch] > 19)
	lower = 1;
      if (y != height - 4 && dp[u + 2 * tpitch] > 19)
	lower2 = 1;
     } IACA_END
}
