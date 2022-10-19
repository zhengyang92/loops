#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int round, unsigned int *dest, int c, int shift, int tmp,
    const int len, const int *src)
{
  for (i = 0; i < len; i++)
    {
      tmp = (int) (((int64_t) src[i] * c + (int64_t) 0x1000000000) >> 37);
      dest[i] += (tmp + round) >> shift;
}}
