#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned int p, uint16_t left_sum[2][8], int a, int j)
{
  for (j = 0; j < 8; j++)
     { IACA_START
      p = abs (i - j);
      left_sum[p & 1][j] += a >> (p >> 1);
     } IACA_END
}
