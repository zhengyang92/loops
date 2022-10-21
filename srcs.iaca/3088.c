#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * pd)
{
  for (i--; i >= 0; i--)
     { IACA_START
      pd[2 * i + 1] = (pd[i] & 15) * 0x11;
      pd[2 * i + 0] = (pd[i] >> 4) * 0x11;
     } IACA_END
}
