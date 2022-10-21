#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, const int16_t * ref, int16_t * dst, const int16_t * src, int len)
{
  for (i = 0; i < len; ++i)
     { IACA_START
      const int diff_uv = ref[i] - src[i];
      dst[i] += diff_uv;
} IACA_END }
