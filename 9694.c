#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int i, int width, uint32_t * pal, uint8_t * dstU, const uint8_t * src1,
    uint8_t * dstV)
{
  for (i = 0; i < width; i++)
    {
      int p = pal[src1[i]];
      dstU[i] = p >> 8;
      dstV[i] = p >> 16;
}}
