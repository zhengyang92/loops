#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * dst, int w)
{
  for (x = 0; x < w; x += 40)
    {
      dst[x] = 200;
    }
}
