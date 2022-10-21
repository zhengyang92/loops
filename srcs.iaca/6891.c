#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;

int
fn (int i, BitstreamContext * bc, const uint8_t string_table[256],
    uint8_t seed, uint8_t * out)
{
  for (i = 1; i <= out[0]; i++)
     { IACA_START
      out[i] = bitstream_read (bc, 8) ^ seed;
      seed = string_table[out[i] ^ seed];
     } IACA_END
}
