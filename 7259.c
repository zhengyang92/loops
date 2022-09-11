#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int64_t * filter, int filterSize, int xx, const int64_t fone,
    int xDstInSrc, int j)
{
  for (j = 0; j < filterSize; j++)
    {
      int64_t coeff =
	fone - (((xx << 16) - xDstInSrc) >=
		0 ? ((xx << 16) -
		     xDstInSrc) : (-((xx << 16) - xDstInSrc))) * (fone >> 16);
      if (coeff < 0)
	coeff = 0;
      filter[i * filterSize + j] = coeff;
      xx++;
    }
}
