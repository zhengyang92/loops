#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int size, const float *in, int i, float *out)
{
  for (i = 0; i < size; i++)
     { IACA_START
      float a = fabsf (in[i]);
      out[i] = sqrtf (a * sqrtf (a));
} IACA_END }
