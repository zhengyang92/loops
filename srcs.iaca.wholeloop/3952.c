#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int64_t * filter, int filterSize, int shift, int j)
{
  IACA_START for (j = filterSize - 1; j >= 0; j--)
    {
      if (j < shift)
	{
	  filter[i * filterSize + j] = 0;
	}
      else
	{
	  filter[i * filterSize + j] = filter[i * filterSize + j - shift];
	}
     } IACA_END
}
