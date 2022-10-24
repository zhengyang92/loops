#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef VP8LStreaks;
typedef VP8LBitEntropy;

int
fn (const uint32_t * Y, const uint32_t * X, VP8LStreaks * const stats,
    int length, VP8LBitEntropy * const bit_entropy, uint32_t xy_prev)
{
  int i_prev = 0;
  int i = 1;
  IACA_START for (i = 1; i < length; ++i)
    {
      const uint32_t xy = X[i] + Y[i];
      if (xy != xy_prev)
	{
	  GetEntropyUnrefinedHelper (xy, i, &xy_prev, &i_prev, bit_entropy,
				     stats);
	}
     } IACA_END
}
