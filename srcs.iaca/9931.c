#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, const uint8_t * left, uint8_t * dst, int size)
{
  for (j = 0; j < size; ++j)
     { IACA_START
      memset (dst + j * 32, left[j], size);
     } IACA_END
}
