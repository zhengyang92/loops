#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;

int
fn (int i, BitstreamContext * bc, int num_subbands, int subband_vlc_index[32],
    int sf_index[32])
{
  IACA_START for (i = 0; i <= num_subbands; i++)
    {
      if (subband_vlc_index[i] != 0)
	sf_index[i] = bitstream_read (bc, 6);
     } IACA_END
}
