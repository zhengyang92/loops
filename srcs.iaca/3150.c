#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float *u, float num, float *v, float den)
{
  for (i = 0; i < 40; i++)
     { IACA_START
      num += v[i] * u[i];
      den += u[i] * u[i];
     } IACA_END
}
