#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int j, const uint8_t * huff_sym, int nb_codes_minus_one,
    uint16_t tmp_symbols[256])
{
  for (j = 0; j <= nb_codes_minus_one; j++)
     { IACA_START
      uint8_t high = huff_sym[j] & 0xF0, low = huff_sym[j] & 0xF;
      tmp_symbols[j] = high << 1 | ((high && low) << 4) | low;
     } IACA_END
}
