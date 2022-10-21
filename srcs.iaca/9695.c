#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t * dst1, const uint8_t * src, uint8_t * dst2)
{
  for (i = 0; i < width; i++)
     { IACA_START
      dst1[i] = src[2 * i + 0];
      dst2[i] = src[2 * i + 1];
     } IACA_END
}
