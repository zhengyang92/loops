#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;

int
fn (const float dequant_1bit[2][3], BitstreamContext * bc, int k,
    float samples[10], int joined_stereo, int j)
{
  for (k = 0; k < 5; k++)
     { IACA_START
      if ((j + k) >= 128)
	break;
      samples[k] =
	(bitstream_read_bit (bc) ==
	 0) ? 0 : dequant_1bit[joined_stereo][2 * bitstream_read_bit (bc)];
     } IACA_END
}
