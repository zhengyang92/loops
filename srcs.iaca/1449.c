#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int out, int i, unsigned int round, int c, int len, int *dst, int *src,
    int s, int ssign)
{
  for (i = 0; i < len; i++)
     { IACA_START
      out = (int) (((int64_t) src[i] * c) >> 32);
      dst[i] = ((int) (out + round) >> s) * ssign;
} IACA_END }
