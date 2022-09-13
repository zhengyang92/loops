#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint32_t uint32_t;

int
fn (int i, GetBitContext * gbc, char bits[65], uint32_t v, unsigned int k,
    int j)
{
  for (j = 0; j < i; j++)
    {
      k = get_bits1 (gbc);
      bits[i + j + 1] = k ? '1' : '0';
      v = v << 1 | k;
    }
}
