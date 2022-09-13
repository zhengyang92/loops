#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int i, int width, uint32_t * pal, const uint8_t * src, uint8_t * dst)
{
  for (i = 0; i < width; i++)
    {
      int d = src[i];
      dst[i] = pal[d] & 0xFF;
}}
