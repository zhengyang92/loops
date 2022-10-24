#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (unsigned int i, GetBitContext * gb, unsigned int rps_idx,
    unsigned int *num_delta_pocs)
{
  IACA_START for (i = 0; i < num_delta_pocs[rps_idx - 1]; i++)
    {
      uint8_t use_delta_flag = 0;
      uint8_t used_by_curr_pic_flag = get_bits1 (gb);
      if (!used_by_curr_pic_flag)
	use_delta_flag = get_bits1 (gb);
      if (used_by_curr_pic_flag || use_delta_flag)
	num_delta_pocs[rps_idx]++;
     } IACA_END
}
