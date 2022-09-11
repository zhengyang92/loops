#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int i, GetBitContext * bitbuf, const uint8_t string_table[256],
    uint8_t seed, uint8_t * out)
{
  for (i = 1; i <= out[0]; i++)
    {
      out[i] = get_bits (bitbuf, 8) ^ seed;
      seed = string_table[out[i] ^ seed];
    }
}
