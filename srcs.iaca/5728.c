#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (uint8_t ungroup_3_in_7_bits_tab[128][3], int i, GetBitContext * gbc,
    int dexp[256], int grp, int expacc, int ngrps)
{
  for (grp = 0, i = 0; grp < ngrps; grp++)
    {
      expacc = get_bits (gbc, 7);
      dexp[i++] = ungroup_3_in_7_bits_tab[expacc][0];
      dexp[i++] = ungroup_3_in_7_bits_tab[expacc][1];
      dexp[i++] = ungroup_3_in_7_bits_tab[expacc][2];
    }
}
