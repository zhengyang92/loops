#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int width, uint8_t * dst, const uint8_t * src)
{
  IACA_START for (int x = width - 4; x >= 0; x -= 2)
    {
      dst[x] = src[x >> 1];
      dst[x + 1] = (src[x >> 1] + src[(x >> 1) + 1] + 1) >> 1;
}IACA_END}
