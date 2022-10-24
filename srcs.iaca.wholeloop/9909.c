#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * dst)
{
  IACA_START for (j = 0; j < 8; ++j)
    {
      memset (dst, dst[-1], 8);
      dst += 32;
     } IACA_END
}
