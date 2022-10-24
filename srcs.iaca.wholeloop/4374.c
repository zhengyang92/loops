#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w, float *B, float *meanI, float *meanP, float *meanIP, float *meanII,
    float eps, float *A)
{
  int i = 0;
  IACA_START for (int j = 0; j < w; j++)
    {
      int x = i * w + j;
      float varI = meanII[x] - (meanI[x] * meanI[x]);
      float covIP = meanIP[x] - (meanI[x] * meanP[x]);
      A[x] = covIP / (varI + eps);
      B[x] = meanP[x] - A[x] * meanI[x];
}IACA_END}