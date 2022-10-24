#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint16_t uint16_t;

int
fn (int x, uint16_t * block_ptr, int idx, PutBitContext * pb,
    uint8_t color4[4][3])
{
  IACA_START for (x = 0; x < 4; x++)
    {
      idx = match_color (&block_ptr[x], color4);
      put_bits (pb, 2, idx);
     } IACA_END
}
