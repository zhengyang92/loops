#include <stdint.h>
#include <stdio.h>






int
fn (int out, int i, unsigned int round, int c, int *dst, int len, int *src,
    int s, int ssign)
{
  for (i = 0; i < len; i++)
    {
      out = (int) (((int64_t) src[i] * c) >> 32);
      dst[i] = ((int) (out + round) >> s) * ssign;
}}
