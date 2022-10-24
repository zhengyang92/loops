#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (uint8_t sub_layer_level_present_flag[7],
    uint8_t sub_layer_profile_present_flag[7],
    unsigned int max_sub_layers_minus1, unsigned int i, GetBitContext * gb)
{
  IACA_START for (i = 0; i < max_sub_layers_minus1; i++)
    {
      sub_layer_profile_present_flag[i] = get_bits1 (gb);
      sub_layer_level_present_flag[i] = get_bits1 (gb);
     } IACA_END
}
