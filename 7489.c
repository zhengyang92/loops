#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float *bptr, int x, const uint16_t * src16, const int width)
{
  for (x = 0; x < width; x++)
    {
      bptr[x] = src16[x];
    }
}
