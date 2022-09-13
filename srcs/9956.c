#include <stdint.h>
#include <stdio.h>




typedef VP8LBitEntropy;
typedef __uint32_t uint32_t;
typedef VP8LStreaks;

int
fn (int i, uint32_t x_prev, const uint32_t * X, VP8LStreaks * const stats,
    int length, VP8LBitEntropy * const bit_entropy)
{
  int i_prev = 0;
  for (i = 1; i < length; ++i)
    {
      const uint32_t x = X[i];
      if (x != x_prev)
	{
	  GetEntropyUnrefinedHelper (x, i, &x_prev, &i_prev, bit_entropy,
				     stats);
	}
    }
}
