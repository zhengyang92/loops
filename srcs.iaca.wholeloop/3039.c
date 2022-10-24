#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * linear_to_xlaw, int mask)
{
  IACA_START for (; j < 8192; j++)
    {
      linear_to_xlaw[8192 - j] = (127 ^ (mask ^ 0x80));
      linear_to_xlaw[8192 + j] = (127 ^ mask);
     } IACA_END
}
