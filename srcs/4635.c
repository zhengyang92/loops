#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int mode_list[128], int list_start, int coef_list[128], int i, int mask,
    int ccoef, int16_t * block, const uint8_t bink_scan[64], int sign,
    GetBitContext * gb, int nz_coeff[64], int masks_count)
{
  int nz_coeff_count = 0;
  for (i = 0; i < 4; i++, ccoef++)
    {
      if (get_bits1 (gb))
	{
	  coef_list[--list_start] = ccoef;
	  mode_list[list_start] = 3;
	}
      else
	{
	  nz_coeff[nz_coeff_count++] = bink_scan[ccoef];
	  sign = -get_bits1 (gb);
	  block[bink_scan[ccoef]] = (mask ^ sign) - sign;
	  masks_count--;
	  if (masks_count < 0)
	    return 0;
	}
    }
}
