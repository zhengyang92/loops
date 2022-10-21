#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t buf3[4096], int i, const uint8_t * buf2)
{
  for (i = 0; i < 8; i += 2)
     { IACA_START
      buf3[i] = buf2[i + 1];
      buf3[i + 1] = buf2[i];
     } IACA_END
}
