#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float exp2_val, int i, float root_val, const float exp2_tab[2],
    float rootpow2tab[127], float pow2tab[127])
{
  IACA_START for (i = -63; i < 64; i++)
    {
      if (!(i & 1))
	root_val *= 2;
      pow2tab[63 + i] = exp2_val;
      rootpow2tab[63 + i] = root_val * exp2_tab[i & 1];
      exp2_val *= 2;
     } IACA_END
}
