#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int dst_size, int dst_index, const float *src, int64_t incr, float *dst,
    int64_t index2)
{
  for (dst_index = 0; dst_index < dst_size; dst_index++)
    {
      dst[dst_index] = src[index2 >> 32];
      index2 += incr;
    }
}
