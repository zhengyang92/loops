#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float BETA, int ldc, float *C, int N)
{
  for (j = 0; j < N; ++j)
    {
      C[i * ldc + j] *= BETA;
    }
}
