#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * dst1, int width, const uint8_t * src, uint8_t * dst2)
{
  IACA_START for (i = 0; i < width; i++)
    {
      dst1[i] = src[2 * i + 0];
      dst2[i] = src[2 * i + 1];
     } IACA_END
}
