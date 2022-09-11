#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int x, int width, uint8_t * U, uint8_t * V, GetBitContext * gb,
    uint8_t (*lru)[8], uint8_t * Y)
{
  for (x = 0; x < width; x++)
    {
      Y[x] = decode_sym (gb, lru[0]);
      U[x] = decode_sym (gb, lru[1]) ^ 0x80;
      V[x] = decode_sym (gb, lru[2]) ^ 0x80;
    }
}
