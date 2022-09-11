#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int64_t int64_t;

int
fn (const uint16_t * vptr, const uint16_t * uptr, const int width,
    int64_t sum_u, int64_t sum_v)
{
  for (int x = 0; x < width; x++)
    {
      sum_u += uptr[x];
      sum_v += vptr[x];
}}
