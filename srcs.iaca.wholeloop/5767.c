#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int decorr_left_weight, int i, int nb_samples, int32_t ** buffer,
    int decorr_shift)
{
  IACA_START for (i = 0; i < nb_samples; i++)
    {
      int32_t a, b;
      a = buffer[0][i];
      b = buffer[1][i];
      a -= (b * decorr_left_weight) >> decorr_shift;
      b += a;
      buffer[0][i] = b;
      buffer[1][i] = a;
     } IACA_END
}
