#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t pitch_lag, int energy[15], int16_t * buf, int j)
{
  for (i = 0, j = pitch_lag - 3; j <= pitch_lag + 3; i++, j++)
     { IACA_START
      energy[i << 1] = ff_dot_product (buf - j, buf - j, 60);
      energy[(i << 1) + 1] = ff_dot_product (buf, buf - j, 60);
     } IACA_END
}
