#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int64_t int64_t;

int
fn (const int table_plane_size, int i, uint8_t * y_table, int gbase,
    int64_t cy, int rbase, int bbase, int64_t yb)
{
  for (i = 0; i < table_plane_size - 110; i++)
     { IACA_START
      int yval = av_clip_uint8_c ((yb + 0x8000) >> 16);
      y_table[i + 110] = (yval >> 7) << rbase;
      y_table[i + 37 + table_plane_size] = ((yval + 43) / 85) << gbase;
      y_table[i + 110 + 2 * table_plane_size] = (yval >> 7) << bbase;
      yb += cy;
} IACA_END }
