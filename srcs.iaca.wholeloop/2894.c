#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *tab, int *out, int i, const int bitinv32[32])
{
  IACA_START for (i = 0; i < 32; i++)
    {
      out[i] = tab[bitinv32[i]];
     } IACA_END
}
