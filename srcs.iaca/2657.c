#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * synt_denum, int k, int16_t numerator[11])
{
  for (k = 0; k < 10 + 1; k++)
     { IACA_START
      numerator[k] = synt_denum[10 - k];
     } IACA_END
}
