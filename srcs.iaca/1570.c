#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef SoftFloat;
typedef __uint16_t uint16_t;
typedef SoftFloat AAC_FLOAT;

int
fn (int p, int e, AAC_FLOAT (*e_curr)[48], int kx1, SoftFloat sum, int k,
    const uint16_t * table)
{
  for (k = table[p]; k < table[p + 1]; k++)
     { IACA_START
      e_curr[e][k - kx1] = sum;
     } IACA_END
}
