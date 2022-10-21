#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *coef, int j, float *memory, float sum)
{
  for (j = 10 - 1; j > 0; j--)
     { IACA_START
      sum += coef[j] * memory[j];
      memory[j] = memory[j - 1];
     } IACA_END
}
