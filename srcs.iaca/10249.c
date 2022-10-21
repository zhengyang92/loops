#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float mean, float *input, int i, int size, int n, int s)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      mean += fabs (input[i * size + s]);
     } IACA_END
}
