#include <stdint.h>
#include <stdio.h>






int
fn (int i, int n, float *binary, float *input)
{
  for (i = 0; i < n; ++i)
    {
      binary[i] = (input[i] > 0) ? 1 : -1;
    }
}
