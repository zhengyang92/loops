#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, float *bptr, int x, const int width)
{
  for (x = 0; x < width; x++)
    {
      bptr[x] = src[x];
    }
}
