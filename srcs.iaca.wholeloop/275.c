#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * dst, int w)
{
  IACA_START for (x = 0; x < w; x += 80)
    {
      dst[x] = 200;
     } IACA_END
}
