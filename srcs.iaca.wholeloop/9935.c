#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int x, uint32_t avg, int y, const uint8_t * ref)
{
  IACA_START for (x = 0; x < 4; ++x)
    {
      avg += ref[x + y * 32];
     } IACA_END
}
