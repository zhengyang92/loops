#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int i)
{
  int DC = 8;
  for (i = 0; i < 16; ++i)
     { IACA_START
      DC += dst[i - 32];
     } IACA_END
}
