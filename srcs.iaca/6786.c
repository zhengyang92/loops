#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;

int
fn (const float dequant_1bit[2][3], BitstreamContext * bc, int k,
    float samples[10], int joined_stereo, int j)
{
  for (k = 0; k < 5; k++)
    {
      if ((j + 2 * k) >= 128)
	break;
      samples[2 * k] =
	bitstream_read_bit (bc) ? dequant_1bit[joined_stereo][2 *
							      bitstream_read_bit
							      (bc)] : 0;
    }
}
