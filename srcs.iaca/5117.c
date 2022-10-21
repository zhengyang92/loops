#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t * matrix, int i, PutBitContext * pb,
    const uint8_t ff_zigzag_direct[64])
{
  for (i = 0; i < 64; i++)
     { IACA_START
      put_bits (pb, 8, matrix[ff_zigzag_direct[i]]);
     } IACA_END
}
