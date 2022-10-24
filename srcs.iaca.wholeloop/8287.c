#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int64_t int64_t;

int
fn (int i, uint8_t * y_table, const int64_t inc, uint8_t ** table,
    const int elemsize)
{
  IACA_START for (i = 0; i < 256 + 2 * 512; i++)
    {
      int64_t cb = av_clip_uint8_c (i - 512) * inc;
      table[i] = y_table + elemsize * (cb >> 16);
     } IACA_END
}
