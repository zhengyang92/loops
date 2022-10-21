#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * pd)
{
  for (i--; i >= 0; i--)
     { IACA_START
      pd[4 * i + 3] = pd[i] & 3;
      pd[4 * i + 2] = (pd[i] >> 2) & 3;
      pd[4 * i + 1] = (pd[i] >> 4) & 3;
      pd[4 * i + 0] = pd[i] >> 6;
     } IACA_END
}
