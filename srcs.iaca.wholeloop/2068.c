#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (int max_rice_param, int i, uint64_t sum[4], int n, int k)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      k = find_optimal_param (2 * sum[i], n, max_rice_param);
      sum[i] = (((n) * ((k) + 1)) + ((2 * sum[i] - (n >> 1)) >> (k)));
     } IACA_END
}
