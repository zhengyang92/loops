#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int size, float *output, int b, int n, float *scales)
{
  for (j = 0; j < size; ++j)
     { IACA_START
      output[(b * n + i) * size + j] *= scales[i];
     } IACA_END
}
