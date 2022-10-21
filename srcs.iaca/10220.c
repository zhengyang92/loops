#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float BETA, int ldc, float *C, int N)
{
  for (j = 0; j < N; ++j)
     { IACA_START
      C[i * ldc + j] *= BETA;
     } IACA_END
}
