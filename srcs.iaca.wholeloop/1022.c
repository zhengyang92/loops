#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *coeffs)
{
  float sum = 0.f;
  IACA_START for (int i = 0; i < 4; i++)
    {
      coeffs[i] /= sum;
}IACA_END}
