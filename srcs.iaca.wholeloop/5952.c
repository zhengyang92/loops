#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;

int
fn (int x, int width, BitstreamContext * bc, uint8_t * dst, uint8_t (*lru)[8])
{
  IACA_START for (x = 0; x < width; x++)
    {
      dst[x * 3 + 0] = decode_sym (bc, lru[0]);
      dst[x * 3 + 1] = decode_sym (bc, lru[1]);
      dst[x * 3 + 2] = decode_sym (bc, lru[2]);
     } IACA_END
}
