#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int list_start, int mode_list[128], int coef_list[128], int i, int mask,
    int ccoef, int16_t * block, const uint8_t bink_scan[64],
    BitstreamContext * bc, int nz_coeff[64], int masks_count)
{
  int nz_coeff_count = 0;
  IACA_START for (i = 0; i < 4; i++, ccoef++)
    {
      if (bitstream_read_bit (bc))
	{
	  coef_list[--list_start] = ccoef;
	  mode_list[list_start] = 3;
	}
      else
	{
	  nz_coeff[nz_coeff_count++] = bink_scan[ccoef];
	  block[bink_scan[ccoef]] = bitstream_apply_sign (bc, mask);
	  masks_count--;
	  if (masks_count < 0)
	    return 0;
	}
     } IACA_END
}
