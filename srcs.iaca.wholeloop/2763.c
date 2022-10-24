#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef double LPC_TYPE;

int
fn (int max_order, int i, LPC_TYPE gen0[32], LPC_TYPE gen1[32],
    LPC_TYPE * ref, int j)
{
  IACA_START for (j = 0; j < max_order - i; j++)
    {
      gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
      gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
     } IACA_END
}
