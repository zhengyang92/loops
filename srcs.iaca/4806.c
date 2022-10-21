#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * tmp_cb, int j, uint16_t * tmp_cr, const int bit_depth)
{
  for (j = 0; j < 8; j++)
     { IACA_START
      tmp_cb[j] = tmp_cr[j] = 1 << (bit_depth - 1);
     } IACA_END
}
