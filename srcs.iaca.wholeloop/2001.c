#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *filter_coeffs, int i, float *memory, int j, float *samples)
{
  IACA_START for (j = 10 - 1; j > 0; j--)
    {
      samples[i] -= filter_coeffs[j] * memory[j];
      memory[j] = memory[j - 1];
     } IACA_END
}
