#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int ldc, float A_PART, int k, float *C, int ldb, int N,
    float *B)
{
  IACA_START for (j = 0; j < N; ++j)
    {
      C[i * ldc + j] += A_PART * B[k * ldb + j];
     } IACA_END
}
