#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * const y_dst)
{
  IACA_START for (j = -1; j < 16; ++j)
    {
      Copy32b (&y_dst[j * 32 - 4], &y_dst[j * 32 + 12]);
     } IACA_END
}
