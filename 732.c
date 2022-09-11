#include <stdint.h>
#include <stdio.h>






int
fn (double *A, int m, int n)
{
  int k = 0;
  for (int i = k + 1; i < n; i++)
    {
      double t2 = A[i + n * m];
      A[i + n * m] = A[i + n * k];
      A[i + n * k] = t2;
}}
