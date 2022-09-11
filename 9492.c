#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int width, uint8_t * d, unsigned int v, const uint8_t * src, int j)
{
  for (j = 0; j < width; j++)
    {
      v = ((const uint32_t *) src)[j];
      d[0] = v >> 16;
      d[1] = v >> 8;
      d[2] = v;
      d[3] = v >> 24;
      d += 4;
}}
