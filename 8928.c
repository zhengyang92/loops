#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int dst_size, int dst_index, int16_t * dst, int64_t incr,
    const int16_t * src, int64_t index2)
{
  for (dst_index = 0; dst_index < dst_size; dst_index++)
    {
      dst[dst_index] = src[index2 >> 32];
      index2 += incr;
    }
}
