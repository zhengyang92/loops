#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * const y_dst)
{
  IACA_START for (j = 0; j < 16; ++j)
    {
      y_dst[j * 32 - 1] = 129;
     } IACA_END
}
