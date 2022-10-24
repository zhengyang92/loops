#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int dst_size, int dst_index, int32_t * dst, int64_t incr,
    const int32_t * src, int64_t index2)
{
  IACA_START for (dst_index = 0; dst_index < dst_size; dst_index++)
    {
      dst[dst_index] = src[index2 >> 32];
      index2 += incr;
     } IACA_END
}
