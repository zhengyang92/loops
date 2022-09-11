#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint32_t uint32_t;

int
fn (const uint32_t * res_end, int parts, const uint32_t * res, int i, int n,
    int kmax, int k, uint64_t (*sums)[256], int pmax)
{
  for (i = 0; i < parts; i++)
    {
      if (kmax)
	{
	  uint64_t sum = (1LL + k) * (res_end - res);
	  while (res < res_end)
	    sum += *(res++) >> k;
	  sums[k][i] = sum;
	}
      else
	{
	  uint64_t sum = 0;
	  while (res < res_end)
	    sum += *(res++);
	  sums[k][i] = sum;
	}
      res_end += n >> pmax;
    }
}
