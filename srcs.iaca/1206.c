#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, const uint32_t * keys, uint32_t v)
{
  for (i = 1; i < 5; i++)
     { IACA_START
      v = (v >> 16) | (v << 16);
      v *= keys[i];
     } IACA_END
}
