#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int i, uint8_t vec[3][4], const int val_shift, int vals[3],
    int vec_len[3], int k, int prev_mode[16], int prev_pix[3],
    uint8_t * dst[3], GetBitContext * gb, int split)
{
  for (k = 0; k < split; k++)
     { IACA_START
      *dst[i]++ =
	get_value_cached (gb, vals[i], vec[i], vec_len[i], i, val_shift,
			  prev_pix);
      prev_mode[k] = ((vals)[0] | ((vals)[1] << 3) | ((vals)[2] << 6));
     } IACA_END
}
