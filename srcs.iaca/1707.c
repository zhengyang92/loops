#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int mode_list[128], int list_start, int *coef_idx, int coef_list[128],
    int i, int bits, int ccoef, int t, int sign, int32_t * block,
    const uint8_t * scan, GetBitContext * gb)
{
  int coef_count = 0;
  for (i = 0; i < 4; i++, ccoef++)
    {
      if (get_bits1 (gb))
	{
	  coef_list[--list_start] = ccoef;
	  mode_list[list_start] = 3;
	}
      else
	{
	  if (!bits)
	    {
	      t = 1 - (get_bits1 (gb) << 1);
	    }
	  else
	    {
	      t = get_bits (gb, bits) | 1 << bits;
	      sign = -get_bits1 (gb);
	      t = (t ^ sign) - sign;
	    }
	  block[scan[ccoef]] = t;
	  coef_idx[coef_count++] = ccoef;
	}
    }
}
