#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float norm[22], const float *Ex, float newE[22])
{
  for (int i = 0; i < 22; i++)
     { IACA_START
      norm[i] = sqrtf (Ex[i] / (1e-8 + newE[i]));
} IACA_END }
