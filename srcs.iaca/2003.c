#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *memory, const float *coef, float sum, int j)
{
  for (j = 10 - 1; j > 0; j--)
     { IACA_START
      sum += coef[j] * memory[j];
      memory[j] = memory[j - 1];
     } IACA_END
}
