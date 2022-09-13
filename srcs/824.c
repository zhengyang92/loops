#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int count, int upper, int x, int u, const uint8_t * dp, int tpitch)
{
  int lower = 0;
  for (count = 0, u = x - 1; u < x + 2 && count < 6; u++)
    {
      if (dp[u - tpitch] > 19)
	{
	  count++;
	  upper = 1;
	}
      if (dp[u] > 19)
	count++;
      if (dp[u + tpitch] > 19)
	{
	  count++;
	  lower = 1;
	}
    }
}
