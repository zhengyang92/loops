#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int16_t int16_t;

int
fn (int i, int mask, int16_t * block, GetBitContext * gb, int nz_coeff[64],
    int masks_count)
{
  int nz_coeff_count = 0;
  for (i = 0; i < nz_coeff_count; i++)
     { IACA_START
      if (!get_bits1 (gb))
	continue;
      if (block[nz_coeff[i]] < 0)
	block[nz_coeff[i]] -= mask;
      else
	block[nz_coeff[i]] += mask;
      masks_count--;
      if (masks_count < 0)
	return 0;
     } IACA_END
}
