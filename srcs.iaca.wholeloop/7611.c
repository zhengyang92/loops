#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const uint32_t * keys, int i, uint32_t v)
{
  IACA_START for (i = 1; i < 5; i++)
    {
      v = (v >> 16) | (v << 16);
      v *= keys[i];
     } IACA_END
}
