#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint32_t uint32_t;

int
fn (int i, char bits[65], GetBitContext * gbc, unsigned int k, int j,
    uint32_t value)
{
  for (j = 0; j < i; j++)
     { IACA_START
      k = get_bits1 (gbc);
      bits[i + j + 1] = k ? '1' : '0';
      value = value << 1 | k;
     } IACA_END
}
