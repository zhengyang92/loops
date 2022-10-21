#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int64_t int64_t;

int
fn (int i, int32_t ** filterPos, int64_t * filter, int filterSize, int srcW,
    int64_t acc, int j)
{
  for (j = filterSize - 1; j >= 0; j--)
     { IACA_START
      if ((*filterPos)[i] + j >= srcW)
	{
	  acc += filter[i * filterSize + j];
	  filter[i * filterSize + j] = 0;
	}
     } IACA_END
}
