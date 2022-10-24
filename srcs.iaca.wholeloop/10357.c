#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float *X, float *OUT, int NX)
{
  int index = 0;
  IACA_START for (i = 0; i < NX; ++i)
    {
      OUT[index++] = X[j * NX + i];
     } IACA_END
}
