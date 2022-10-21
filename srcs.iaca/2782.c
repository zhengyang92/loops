#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, const uint8_t * src, uint8_t * dst, int left)
{
  for (i = 0; i < width; i++)
     { IACA_START
      dst[i] = src[i] - left;
      left = src[i];
     } IACA_END
}
