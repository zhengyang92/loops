#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int k, const int t, int sum, uint16_t coarse[32])
{
  for (k = 0; k < (1 << ((9 + 1) / 2)); k++)
    {
      sum += coarse[k];
      if (sum > t)
	{
	  sum -= coarse[k];
	  break;
	}
    }
}
