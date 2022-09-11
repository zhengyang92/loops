#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int w, uint32_t sum, uint32_t * dst, const uint8_t * src,
    int dst_linesize)
{
  for (int x = 1; x < w; x++)
    {
      sum += src[x - 1];
      dst[x] = sum + dst[x - dst_linesize];
}}
