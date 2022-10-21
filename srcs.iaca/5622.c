#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int layer, int sample_rate, int lsf,
    const uint16_t avpriv_mpa_bitrate_tab[2][3][15], int frame_size, int size,
    int bitrate_index)
{
  for (bitrate_index = 2; bitrate_index < 30; bitrate_index++)
     { IACA_START
      frame_size = avpriv_mpa_bitrate_tab[lsf][layer - 1][bitrate_index >> 1];
      frame_size =
	(frame_size * 144000) / (sample_rate << lsf) + (bitrate_index & 1);
      if (frame_size == size)
	break;
     } IACA_END
}
