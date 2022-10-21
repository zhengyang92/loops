#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int ldc, int k, float *C, int ldb, int N, float *B)
{
  for (j = 0; j < N; ++j)
     { IACA_START
      C[i * ldc + j] += B[k * ldb + j];
     } IACA_END
}
