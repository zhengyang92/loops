#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int p, uint8_t * last, int bpp, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < bpp; i++)
    {
      p = (last[i] >> 1);
      dst[i] = p + src[i];
    }
}
