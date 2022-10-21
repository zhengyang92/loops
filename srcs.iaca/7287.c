#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int *table, const int inc, int64_t cb, int off, const int elemsize)
{
  for (i = 0; i < 256; i++)
     { IACA_START
      table[i] = elemsize * (off + (cb >> 16));
      cb += inc;
     } IACA_END
}
