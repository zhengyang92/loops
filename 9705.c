#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ydst, int i, const int chromWidth, const uint8_t * src)
{
  for (i = 0; i < chromWidth; i++)
    {
      ydst[2 * i + 0] = src[4 * i + 0];
      ydst[2 * i + 1] = src[4 * i + 2];
    }
}
