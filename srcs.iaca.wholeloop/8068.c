#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int width, const uint8_t * src1, uint8_t * dst)
{
  IACA_START for (x = 0; x < width - 2; x += 2)
    {
      dst[x] = src1[x];
      dst[x + 1] = (src1[x] + src1[x + 2] + 1) >> 1;
     } IACA_END
}
