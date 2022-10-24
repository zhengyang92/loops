#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *coef, int j, float *memory, float sum)
{
  IACA_START for (j = 10 - 1; j > 0; j--)
    {
      sum += coef[j] * memory[j];
      memory[j] = memory[j - 1];
     } IACA_END
}
