#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * right, int i, int32_t * left, int n, int32_t tmp)
{
  IACA_START for (i = 0; i < n; i++)
    {
      tmp = right[i];
      right[i] = left[i] - right[i];
      left[i] = tmp + (right[i] >> 31);
     } IACA_END
}
