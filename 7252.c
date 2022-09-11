#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int width, int x, uint8_t * dest[3], const uint8_t * src, int inc_size)
{
  for (x = 0; x < width; x++)
    {
      dest[0][x] = src[0];
      dest[1][x] = src[1];
      dest[2][x] = src[2];
      src += inc_size;
    }
}
