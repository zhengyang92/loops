#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const top, int i)
{
  IACA_START for (i = 0; i <= 3; ++i)
    {
      top[i] = top[i + 4];
     } IACA_END
}
