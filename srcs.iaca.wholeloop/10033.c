#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int in_size, uint16_t * const symbols, int i)
{
  IACA_START for (i = 0; i < in_size; ++i)
    {
      symbols[i] = 0;
     } IACA_END
}
