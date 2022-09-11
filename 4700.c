#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;

int
fn (uint8_t id, uint8_t i, const uint16_t bitalloc_12_codes[5][12],
    const uint8_t bitalloc_12_bits[5][12], uint8_t sel, PutBitContext * pb,
    int *values, uint8_t n)
{
  for (i = 0; i < n; i++)
    {
      id = values[i] - 1;
      put_bits (pb, bitalloc_12_bits[sel][id], bitalloc_12_codes[sel][id]);
    }
}
