#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int w, int x, uint8_t * U, int ystride, uint8_t * V, GetBitContext * gb,
    uint8_t (*lru)[8], uint8_t * Y)
{
  IACA_START for (x = 0; x < w; x += 2)
    {
      Y[x + 0 + 0 * ystride] = decode_sym (gb, lru[0]);
      Y[x + 1 + 0 * ystride] = decode_sym (gb, lru[0]);
      Y[x + 0 + 1 * ystride] = decode_sym (gb, lru[0]);
      Y[x + 1 + 1 * ystride] = decode_sym (gb, lru[0]);
      U[x >> 1] = decode_sym (gb, lru[1]) ^ 0x80;
      V[x >> 1] = decode_sym (gb, lru[2]) ^ 0x80;
     } IACA_END
}
