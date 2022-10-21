#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int x, int width, uint8_t * U, uint8_t * V, uint8_t * Y,
    uint8_t (*lru)[8], GetBitContext * gb)
{
  for (x = 0; x < width; x += 2)
     { IACA_START
      Y[x + 0] = decode_sym (gb, lru[0]);
      U[x >> 1] = decode_sym (gb, lru[1]) ^ 0x80;
      V[x >> 1] = decode_sym (gb, lru[2]) ^ 0x80;
     } IACA_END
}
