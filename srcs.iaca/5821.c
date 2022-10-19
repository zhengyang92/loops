#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int16_t int16_t;

int
fn (int i, int mask, int16_t * block, BitstreamContext * bc, int nz_coeff[64],
    int masks_count)
{
  int nz_coeff_count = 0;
  for (i = 0; i < nz_coeff_count; i++)
    {
      if (!bitstream_read_bit (bc))
	continue;
      if (block[nz_coeff[i]] < 0)
	block[nz_coeff[i]] -= mask;
      else
	block[nz_coeff[i]] += mask;
      masks_count--;
      if (masks_count < 0)
	return 0;
    }
}
