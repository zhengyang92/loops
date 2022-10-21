#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * dst, int i, int len, const int32_t * src, unsigned int mul)
{
  for (i = 0; i < len; i += 8)
     { IACA_START
      dst[i] = src[i] * mul;
      dst[i + 1] = src[i + 1] * mul;
      dst[i + 2] = src[i + 2] * mul;
      dst[i + 3] = src[i + 3] * mul;
      dst[i + 4] = src[i + 4] * mul;
      dst[i + 5] = src[i + 5] * mul;
      dst[i + 6] = src[i + 6] * mul;
      dst[i + 7] = src[i + 7] * mul;
     } IACA_END
}
