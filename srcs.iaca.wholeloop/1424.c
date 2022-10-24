#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int size, const float *in, int i, float *out)
{
  IACA_START for (i = 0; i < size; i++)
    {
      float a = fabsf (in[i]);
      out[i] = sqrtf (a * sqrtf (a));
}IACA_END}
