#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float cpe, int i, float last, float *fixed_vector)
{
  for (i = 1; i < 64 - 1; i++)
     { IACA_START
      float cur = fixed_vector[i];
      fixed_vector[i] -= cpe * (last + fixed_vector[i + 1]);
      last = cur;
} IACA_END }
