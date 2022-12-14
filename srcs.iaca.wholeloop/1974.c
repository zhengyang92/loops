#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int x, int width, uint8_t * dst, uint8_t (*lru)[8], GetBitContext * gb)
{
  IACA_START for (x = 0; x < width; x++)
    {
      dst[x * 3 + 0] = decode_sym (gb, lru[0]);
      dst[x * 3 + 1] = decode_sym (gb, lru[1]);
      dst[x * 3 + 2] = decode_sym (gb, lru[2]);
     } IACA_END
}
