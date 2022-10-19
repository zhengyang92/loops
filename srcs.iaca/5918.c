#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __int32_t int32_t;

int
fn (int i, int offset, int levels, int32_t * values, int code,
    const uint32_t ff_inverse[257])
{
  for (i = 0; i < 4; i++)
    {
      int div = ((uint32_t) ((((uint64_t) code) * ff_inverse[levels]) >> 32));
      values[i] = code - offset - div * levels;
      code = div;
}}
