#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int64_t * filter, int filterSize, int64_t sum, int j)
{
  for (j = 0; j < filterSize; j++)
    {
      sum += filter[i * filterSize + j];
    }
}
