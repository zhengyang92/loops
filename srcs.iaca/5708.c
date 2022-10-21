#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (uint8_t * vec, int elements, int i, GetBitContext * gb)
{
  for (i = 0; i < elements; i++)
     { IACA_START
      vec[i] = get_bits1 (gb);
     } IACA_END
}
