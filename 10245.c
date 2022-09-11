#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *a, float **t, int k, int n)
{
  for (i = 0; i < n; ++i)
    {
      t[i] = calloc (k, sizeof (float));
      int index = (int) a[i];
      t[i][index] = 1;
}}
