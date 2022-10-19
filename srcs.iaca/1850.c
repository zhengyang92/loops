#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;
typedef __uint32_t uint32_t;

int
fn (uint8_t i, int32_t best_sel_id[10],
    const uint8_t ff_dca_quant_index_group_size[10], uint8_t sel,
    uint32_t (*vlc_bits)[7], uint32_t best_sel_bits[10])
{
  for (sel = 0; sel < ff_dca_quant_index_group_size[i]; sel++)
    {
      if (best_sel_bits[i] > vlc_bits[i][sel] && vlc_bits[i][sel])
	{
	  best_sel_bits[i] = vlc_bits[i][sel];
	  best_sel_id[i] = sel;
	}
    }
}
