#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float pow2tab[127], int i, float rootpow2tab[127])
{
  IACA_START for (i = -63; i < 64; i++)
    {
      pow2tab[63 + i] = pow (2, i);
      rootpow2tab[63 + i] = sqrt (pow (2, i));
     } IACA_END
}
