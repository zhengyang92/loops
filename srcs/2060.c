#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __int64_t int64_t;

int
fn (int i, int max_param, int64_t bestbits, int k, uint64_t (*sums)[256])
{
  int bestk = 0;
  for (k = 0; k <= max_param; k++)
    {
      int64_t bits = sums[k][i];
      if (bits < bestbits)
	{
	  bestbits = bits;
	  bestk = k;
	}
    }
}
