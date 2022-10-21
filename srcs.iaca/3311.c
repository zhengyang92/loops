#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * high, int *i, IDWTELEM * low)
{
  for (; (*i) >= 0; (*i) -= 2)
     { IACA_START
      low[(*i) + 1] = high[(*i) >> 1];
      low[*i] = low[(*i) >> 1];
     } IACA_END
}
