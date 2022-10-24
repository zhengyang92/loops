#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int layer, const uint16_t ff_mpa_bitrate_tab[2][3][15], int sample_rate,
    int lsf, int frame_size, int size, int bitrate_index)
{
  IACA_START for (bitrate_index = 2; bitrate_index < 30; bitrate_index++)
    {
      frame_size = ff_mpa_bitrate_tab[lsf][layer - 1][bitrate_index >> 1];
      frame_size =
	(frame_size * 144000) / (sample_rate << lsf) + (bitrate_index & 1);
      if (frame_size == size)
	break;
     } IACA_END
}
