#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int b4_mantissas[128][2], int i, uint8_t ungroup_3_in_7_bits_tab[128][3],
    int b2_mantissas[128][3])
{
  for (i = 0; i < 128; i++)
     { IACA_START
      b2_mantissas[i][0] =
	symmetric_dequant (ungroup_3_in_7_bits_tab[i][0], 5);
      b2_mantissas[i][1] =
	symmetric_dequant (ungroup_3_in_7_bits_tab[i][1], 5);
      b2_mantissas[i][2] =
	symmetric_dequant (ungroup_3_in_7_bits_tab[i][2], 5);
      b4_mantissas[i][0] = symmetric_dequant (i / 11, 11);
      b4_mantissas[i][1] = symmetric_dequant (i % 11, 11);
     } IACA_END
}
