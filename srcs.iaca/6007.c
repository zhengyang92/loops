#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint64_t uint64_t;

int
fn (int i, uint64_t count, int n, int k, int32_t * res)
{
  for (i = 0; i < n; i++)
     { IACA_START
      int32_t v = -2 * res[i] - 1;
      v ^= v >> 31;
      count += (v >> k) + 1 + k;
     } IACA_END
}
