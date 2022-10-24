#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int distribution[32], int k, int16_t out[16])
{
  IACA_START for (k = 0; k < 16; ++k)
    {
      ++distribution[out[k]];
     } IACA_END
}
