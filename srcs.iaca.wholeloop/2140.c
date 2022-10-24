#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * dst, int w, const uint8_t * src)
{
  IACA_START for (; x < w; x++)
    {
      dst[x] = src[2 * x];
     } IACA_END
}
