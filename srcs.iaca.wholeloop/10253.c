#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int size, float *delta, int b, int n, float *bias_updates)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      bias_updates[i] += sum_array (delta + size * (i + b * n), size);
     } IACA_END
}
