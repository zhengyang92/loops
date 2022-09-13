#include <stdint.h>
#include <stdio.h>






int
fn (float *a, float s, int n, int i)
{
  for (i = 0; i < n; ++i)
    {
      a[i] += s;
    }
}
