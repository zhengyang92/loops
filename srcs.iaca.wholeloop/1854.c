#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t sum, uint8_t id, uint8_t i, uint8_t sel,
    const uint8_t bitalloc_12_bits[5][12], int *values, uint8_t n)
{
  IACA_START for (i = 0; i < n; i++)
    {
      id = values[i] - 1;
      sum += bitalloc_12_bits[sel][id];
     } IACA_END
}
