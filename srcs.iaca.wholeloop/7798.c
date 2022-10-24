#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int16_t * vector_ptr, int64_t sum, int t, int tmp[120], int shift, int j)
{
  IACA_START for (j = 0; j < 60 * 2; j++)
    {
      t = vector_ptr[j] * (1 << -shift);
      sum += t * t;
      tmp[j] = t;
     } IACA_END
}
