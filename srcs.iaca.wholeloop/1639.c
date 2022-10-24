#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int cb[8], uint8_t lens[256], GetBitContext * gb)
{
  IACA_START for (int i = 0; i < 256; i++)
    {
      int idx = get_bits (gb, 3);
      lens[i] = cb[idx];
}IACA_END}
