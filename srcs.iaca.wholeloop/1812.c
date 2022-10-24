#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int num_codes, int count, int i, uint8_t symbols[256], int j,
    uint8_t bits[256], GetBitContext * gb)
{
  IACA_START for (j = 0; j < num_codes; j++)
    {
      symbols[count] = get_bits (gb, 8);
      bits[count] = i + 1;
      count++;
     } IACA_END
}
