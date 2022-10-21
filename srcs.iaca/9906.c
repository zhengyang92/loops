#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * dst)
{
  int DC = 16;
  for (j = 0; j < 16; ++j)
     { IACA_START
      DC += dst[-1 + j * 32] + dst[j - 32];
     } IACA_END
}
