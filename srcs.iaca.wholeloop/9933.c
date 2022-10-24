#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, const uint8_t * const clip_table, const uint8_t * top,
    uint8_t * dst)
{
  IACA_START for (x = 0; x < 4; ++x)
    {
      dst[x] = clip_table[top[x]];
     } IACA_END
}
