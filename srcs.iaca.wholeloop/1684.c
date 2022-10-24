#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int i, int num_subbands, int subband_vlc_index[32], int sf_index[32],
    GetBitContext * gb)
{
  IACA_START for (i = 0; i <= num_subbands; i++)
    {
      if (subband_vlc_index[i] != 0)
	sf_index[i] = get_bits (gb, 6);
     } IACA_END
}
