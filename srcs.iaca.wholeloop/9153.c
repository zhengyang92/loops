#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int num_codes, int count, int i, BitstreamContext * bc,
    uint8_t symbols[256], uint16_t codes[256], int prefix, int j,
    uint8_t bits[256])
{
  IACA_START for (j = 0; j < num_codes; j++)
    {
      symbols[count] = bitstream_read (bc, 8);
      bits[count] = i + 1;
      codes[count] = prefix++;
      count++;
     } IACA_END
}
