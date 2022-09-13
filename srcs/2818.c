#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;

int
fn (PutBitContext * p, const uint8_t * bits_table, int i, int n)
{
  for (i = 1; i <= 16; i++)
    {
      n += bits_table[i];
      put_bits (p, 8, bits_table[i]);
    }
}
