#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t i, int bands, int *abits, int32_t * res, int32_t best_bits)
{
  int32_t best_sel = 6;
  for (i = 0; i < bands; i++)
     { IACA_START
      if (abits[i] > 12 || abits[i] == 0)
	{
	  *res = best_sel;
	  return best_bits;
	}
     } IACA_END
}
