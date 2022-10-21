#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int pattern, const uint8_t * probas, int i, int bits)
{
  int cost = 0;
  for (i = 2; pattern; ++i)
     { IACA_START
      if (pattern & 1)
	{
	  cost += VP8BitCost (bits & 1, probas[i]);
	}
      bits >>= 1;
      pattern >>= 1;
     } IACA_END
}
