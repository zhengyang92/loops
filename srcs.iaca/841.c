#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float *bptr, int x, uint16_t * dst16, const int width)
{
  for (x = 0; x < width; x++)
    {
      dst16[x] = bptr[x];
    }
}
