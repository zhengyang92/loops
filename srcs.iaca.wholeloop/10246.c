#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float mean, int i, int size, float *weights, int f)
{
  IACA_START for (i = 0; i < size; ++i)
    {
      mean += fabs (weights[f * size + i]);
     } IACA_END
}
