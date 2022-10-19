#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int g, uint8_t (*lru)[8], int x, int width, int r, int is_565,
    uint8_t * dst, GetBitContext * gb, int b)
{
  for (x = 0; x < width; x++)
    {
      b = decode_sym_565 (gb, lru[0], 5);
      g = decode_sym_565 (gb, lru[1], is_565 ? 6 : 5);
      r = decode_sym_565 (gb, lru[2], 5);
      dst[x * 3 + 0] = (r << 3) | (r >> 2);
      dst[x * 3 + 1] = is_565 ? (g << 2) | (g >> 4) : (g << 3) | (g >> 2);
      dst[x * 3 + 2] = (b << 3) | (b >> 2);
    }
}
