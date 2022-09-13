#include <stdint.h>
#include <stdio.h>






int
fn (int i, const uint8_t ff_ac3_ungroup_3_in_5_bits_tab[32][3],
    int b1_mantissas[32][3])
{
  for (i = 0; i < 32; i++)
    {
      b1_mantissas[i][0] =
	symmetric_dequant (ff_ac3_ungroup_3_in_5_bits_tab[i][0], 3);
      b1_mantissas[i][1] =
	symmetric_dequant (ff_ac3_ungroup_3_in_5_bits_tab[i][1], 3);
      b1_mantissas[i][2] =
	symmetric_dequant (ff_ac3_ungroup_3_in_5_bits_tab[i][2], 3);
    }
}
