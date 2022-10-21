#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int32_t int32_t;

int
fn (int32_t * dst1, int32_t * dst2, int i, ptrdiff_t len, const int32_t * src)
{
  for (i = 0; i < len; i++)
     { IACA_START
      int32_t cs = mul23 (src[i], 5931520);
      dst1[i] -= cs;
      dst2[i] -= cs;
     } IACA_END
}
