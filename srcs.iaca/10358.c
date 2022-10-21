#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *Y, int NY, int i, float *OUT)
{
  int index = 0;
  for (i = 0; i < NY; ++i)
     { IACA_START
      OUT[index++] = Y[j * NY + i];
     } IACA_END
}
