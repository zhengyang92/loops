#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int w, int off, uint8_t * src)
{
  for (x = off; x < w; x += 3)
    {
      src[x] += src[x + 1] + 128;
      src[x + 2] += ((src[x] + src[x + 1]) >> 1) + 128;
    }
}
