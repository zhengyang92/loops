#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int size, float *output, int b, int n, float *scales)
{
  IACA_START for (j = 0; j < size; ++j)
    {
      output[(b * n + i) * size + j] *= scales[i];
     } IACA_END
}
