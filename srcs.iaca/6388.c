#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * left, uint8_t * top, int i)
{
  for (i = 0; i < 2 * 32; i++)
     { IACA_START
      left[i] = 128;
      top[i] = 128;
     } IACA_END
}
