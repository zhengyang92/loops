#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int k, int K, float ALPHA, int lda, int ldb, float *B,
    float sum, float *A)
{
  for (k = 0; k < K; ++k)
    {
      sum += ALPHA * A[i + k * lda] * B[k + j * ldb];
    }
}
