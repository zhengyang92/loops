#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t ** src, int x, int width, uint8_t * dest)
{
  for (x = 0; x < width; x++)
    {
      *dest++ = src[0][x];
      *dest++ = src[1][x];
      *dest++ = src[2][x];
    }
}
