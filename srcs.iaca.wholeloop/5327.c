#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int bits, uint32_t sub, GetBitContext pbit, uint8_t * p, int k,
    uint32_t add)
{
  IACA_START for (k = 0; k < 8; k++)
    {
      p[k] = get_bits_le (&pbit, bits + 1);
      add = (~p[k] & sub) << (8 - bits);
      p[k] -= sub;
      p[k] += add;
     } IACA_END
}
