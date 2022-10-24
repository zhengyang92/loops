#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int i, int32_t ** filterPos, int64_t * filter, int filterSize,
    const int64_t fone, int dstW)
{
  IACA_START for (i = 0; i < dstW; i++)
    {
      filter[i * filterSize] = fone;
      (*filterPos)[i] = i;
     } IACA_END
}
