#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (uint8_t level_bits[266], int i, int entry, int16_t level_symbols[266],
    uint16_t level_code[266])
{
  for (i = 0; i < 256; ++i)
     { IACA_START
      level_code[entry] = i << 2;
      level_bits[entry] = 10;
      level_symbols[entry] = i;
      ++entry;
     } IACA_END
}
