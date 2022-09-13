#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, const uint8_t ** src, int width, uint8_t * dest)
{
  for (x = 0; x < width; x++)
    {
      *dest++ = 0xff;
      *dest++ = src[0][x];
      *dest++ = src[1][x];
      *dest++ = src[2][x];
    }
}
