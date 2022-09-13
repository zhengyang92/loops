#include <stdint.h>
#include <stdio.h>






int
fn (float *a, int n, float sum, int i)
{
  for (i = 0; i < n; ++i)
    {
      sum += a[i] * a[i];
    }
}
