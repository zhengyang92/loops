#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * left, uint8_t * top, int i)
{
  IACA_START for (i = 0; i < 2 * 32; i++)
    {
      left[i] = 128;
      top[i] = 128;
     } IACA_END
}
