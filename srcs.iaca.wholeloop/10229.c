#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int N, float *A, int i)
{
  IACA_START for (j = 0; j < N; ++j)
    {
      printf ("%2.4f, ", A[i * N + j]);
     } IACA_END
}
