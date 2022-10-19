#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int minFilterSize, int filter2Size, int64_t * filter,
    int filterSize, int j, int64_t * filter2, int flags)
{
  for (j = 0; j < filterSize; j++)
    {
      if (j >= filter2Size)
	filter[i * filterSize + j] = 0;
      else
	filter[i * filterSize + j] = filter2[i * filter2Size + j];
      if ((flags & 0x80000) && j >= minFilterSize)
	filter[i * filterSize + j] = 0;
    }
}
