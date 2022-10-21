#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int color[4], int64_t weight_sum, int j, int distance[4], int64_t guess)
{
  for (j = 0; j < 4; j++)
     { IACA_START
      int64_t weight = 256 * 256 * 256 * 16 / distance[j];
      guess += weight * (int64_t) color[j];
      weight_sum += weight;
     } IACA_END
}
