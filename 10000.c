#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t * src, int len, const int16_t * ref, int16_t * dst)
{
  int i = 0;
  for (; i < len; ++i)
    {
      const int diff_uv = ref[i] - src[i];
      dst[i] += diff_uv;
}}
