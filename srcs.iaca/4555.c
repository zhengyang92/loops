#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned int *dest, int round, int c, int shift, int tmp,
    const int len, const int *src)
{
  for (i = 0; i < len; i++)
     { IACA_START
      tmp = (int) (((int64_t) src[i] * c + (int64_t) 0x1000000000) >> 37);
      dest[i] += (tmp + round) >> shift;
} IACA_END }
