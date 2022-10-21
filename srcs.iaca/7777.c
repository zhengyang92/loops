#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float sum2, int i, float *in, float scratch[54], int length, float sum1)
{
  for (i = 0, sum1 = 0, sum2 = 0; i < length; i++)
     { IACA_START
      sum1 += in[i] * in[i];
      sum2 += scratch[i] * scratch[i];
     } IACA_END
}
