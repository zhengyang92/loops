#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t prev, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      *dst++ = src[i] - prev;
      prev = src[i];
    }
}
