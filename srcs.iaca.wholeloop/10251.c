#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *biases, int i, int size, float *output, int b, int n)
{
  IACA_START for (j = 0; j < size; ++j)
    {
      output[(b * n + i) * size + j] += biases[i];
     } IACA_END
}
