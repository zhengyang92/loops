#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int i)
{
  int dc0 = 8;
  IACA_START for (i = 0; i < 8; ++i)
    {
      dc0 += dst[i - 32] + dst[-1 + i * 32];
     } IACA_END
}
