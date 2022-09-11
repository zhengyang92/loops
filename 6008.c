#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint32_t uint32_t;

int
fn (int parts, uint32_t * res, int i, int n, uint32_t * res_end,
    uint64_t (*sums)[256], int pmax)
{
  for (i = 0; i < parts; i++)
    {
      uint64_t sum = 0;
      while (res < res_end)
	sum += *(res++);
      sums[pmax][i] = sum;
      res_end += n >> pmax;
    }
}
