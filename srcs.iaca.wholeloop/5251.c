#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (const int (*x)[2], int i, int64_t accu_re)
{
  IACA_START for (i = 1; i < 38; i++)
    {
      accu_re += (uint64_t) x[i][0] * x[i][0];
      accu_re += (uint64_t) x[i][1] * x[i][1];
     } IACA_END
}
