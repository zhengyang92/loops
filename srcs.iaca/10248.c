#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *input, int n, float *binary, int i)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      binary[i] = (input[i] > 0) ? 1 : -1;
     } IACA_END
}
