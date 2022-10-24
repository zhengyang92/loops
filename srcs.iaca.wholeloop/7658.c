#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float AAC_FLOAT;
typedef __uint16_t uint16_t;

int
fn (int p, int e, AAC_FLOAT (*e_curr)[48], int kx1, int k,
    const uint16_t * table)
{
  float sum = 0.0f;
  IACA_START for (k = table[p]; k < table[p + 1]; k++)
    {
      e_curr[e][k - kx1] = sum;
     } IACA_END
}
