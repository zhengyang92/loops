#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float pitch_coef, float *exc, int nsf, int start, float *exc_out)
{
  IACA_START for (int i = 0; i < nsf; i++)
    {
      exc_out[i] = exc[i - start] * pitch_coef;
      exc[i] = exc_out[i];
}IACA_END}
