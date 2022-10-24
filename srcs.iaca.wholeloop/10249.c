#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float mean, float *input, int i, int size, int n, int s)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      mean += fabs (input[i * size + s]);
     } IACA_END
}
