#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;

int
fn (int g, int x, int width, BitstreamContext * bc, int r, uint8_t * dst,
    int is_565, uint8_t (*lru)[8], int b)
{
  IACA_START for (x = 0; x < width; x++)
    {
      b = decode_sym_565 (bc, lru[0], 5);
      g = decode_sym_565 (bc, lru[1], is_565 ? 6 : 5);
      r = decode_sym_565 (bc, lru[2], 5);
      dst[x * 3 + 0] = (r << 3) | (r >> 2);
      dst[x * 3 + 1] = is_565 ? (g << 2) | (g >> 4) : (g << 3) | (g >> 2);
      dst[x * 3 + 2] = (b << 3) | (b >> 2);
     } IACA_END
}
