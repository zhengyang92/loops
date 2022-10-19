#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *memory, const float *coef, float sum, int j)
{
  for (j = 10 - 1; j > 0; j--)
    {
      sum += coef[j] * memory[j];
      memory[j] = memory[j - 1];
    }
}
