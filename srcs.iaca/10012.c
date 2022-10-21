#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t dc[16], uint32_t m2, int k, uint32_t m)
{
  for (m = 0, m2 = 0, k = 0; k < 16; ++k)
     { IACA_START
      m += dc[k];
      m2 += dc[k] * dc[k];
     } IACA_END
}
