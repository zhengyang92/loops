#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int *table, const int64_t inc, int off, const int elemsize)
{
  for (i = 0; i < 256 + 2 * 512; i++)
     { IACA_START
      int64_t cb = av_clip_uint8_c (i - 512) * inc;
      table[i] = elemsize * (off + (cb >> 16));
     } IACA_END
}
