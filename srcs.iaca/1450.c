#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int out, int i, unsigned int round, int c, int len, int *dst, int *src,
    int s, int ssign)
{
  for (i = 0; i < len; i++)
    {
      out = (int) ((int64_t) ((int64_t) src[i] * c + round) >> s);
      dst[i] = out * (unsigned) ssign;
}}
