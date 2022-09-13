#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (const float dequant_1bit[2][3], int k, float samples[10],
    int joined_stereo, int j, GetBitContext * gb)
{
  for (k = 0; k < 5; k++)
    {
      if ((j + k) >= 128)
	break;
      samples[k] =
	(get_bits1 (gb) ==
	 0) ? 0 : dequant_1bit[joined_stereo][2 * get_bits1 (gb)];
    }
}
