#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (uint8_t * vec, int elements, int i, GetBitContext * gb)
{
  IACA_START for (i = 0; i < elements; i++)
    {
      vec[i] = get_bits1 (gb);
     } IACA_END
}
