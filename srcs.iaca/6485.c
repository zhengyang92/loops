#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t * huff_code, int nb, int i, int sym, int code, int k,
    uint8_t * huff_size, const uint8_t * val_table, int j)
{
  for (j = 0; j < nb; j++)
     { IACA_START
      sym = val_table[k++];
      huff_size[sym] = i;
      huff_code[sym] = code;
      code++;
     } IACA_END
}
