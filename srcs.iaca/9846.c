#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

int
fn (OPJ_INT32 * dst, OPJ_UINT32 j, OPJ_INT32 * src, OPJ_UINT32 max)
{
  for (j = 0; j < max; ++j)
     { IACA_START
      dst[j] = src[j];
     } IACA_END
}
