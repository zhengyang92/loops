#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const int16_t * src, int x, int w, uint8_t * dst)
{
  int m = 0;
  for (x = 0; x < w; x++)
    {
      int t = src[x] + 128;
      dst[x] = t;
      m |= t;
}}
