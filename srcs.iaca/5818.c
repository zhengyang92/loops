#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (int mode_list[128], int list_start, int *coef_idx, int coef_list[128],
    int i, int bits, int ccoef, BitstreamContext * bc, int t, int32_t * block,
    const uint8_t * scan)
{
  int coef_count = 0;
  for (i = 0; i < 4; i++, ccoef++)
    {
      if (bitstream_read_bit (bc))
	{
	  coef_list[--list_start] = ccoef;
	  mode_list[list_start] = 3;
	}
      else
	{
	  if (!bits)
	    {
	      t = 1 - (bitstream_read_bit (bc) << 1);
	    }
	  else
	    {
	      t = bitstream_read (bc, bits) | 1 << bits;
	      t = bitstream_apply_sign (bc, t);
	    }
	  block[scan[ccoef]] = t;
	  coef_idx[coef_count++] = ccoef;
	}
    }
}
