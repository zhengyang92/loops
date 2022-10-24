#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint8_t * lens, int i, int max_bits, int prefix, int j,
    uint8_t bits[162], uint16_t codes[162])
{
  int idx = 0;
  IACA_START for (j = 0; j < lens[i]; j++)
    {
      bits[idx] = i + 1;
      codes[idx] = prefix++;
      max_bits = i + 1;
      idx++;
     } IACA_END
}
