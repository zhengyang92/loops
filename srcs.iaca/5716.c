#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int p, int e, int kx1, int k, const uint16_t * table, float (*e_curr)[48])
{
  float sum = 0.0f;
  for (k = table[p]; k < table[p + 1]; k++)
     { IACA_START
      e_curr[e][k - kx1] = sum;
     } IACA_END
}
