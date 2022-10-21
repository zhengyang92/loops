#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int distribution[32], int k, int16_t out[16])
{
  for (k = 0; k < 16; ++k)
     { IACA_START
      ++distribution[out[k]];
     } IACA_END
}
