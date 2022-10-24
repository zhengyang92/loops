#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (uint16_t top_sum[2][8], int i, unsigned int p, int a, int j)
{
  IACA_START for (j = 5; j < 8; j++)
    {
      p = abs (i - j);
      top_sum[p & 1][j] += a >> (p >> 1);
     } IACA_END
}
