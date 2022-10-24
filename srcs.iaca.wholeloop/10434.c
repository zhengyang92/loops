#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int n, float *binary, float *input)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      binary[i] = (input[i] > 0) ? 1 : -1;
     } IACA_END
}
