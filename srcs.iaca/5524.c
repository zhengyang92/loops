#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint8_t uint8_t;

int
fn (const int table_plane_size, uint8_t * y_table, int i, int gbase,
    int64_t cy, int rbase, int bbase, int64_t yb)
{
  for (i = 0; i < table_plane_size - 38; i++)
    {
      int yval = av_clip_uint8_c ((yb + 0x8000) >> 16);
      y_table[i + 16] = ((yval + 18) / 36) << rbase;
      y_table[i + 16 + table_plane_size] = ((yval + 18) / 36) << gbase;
      y_table[i + 37 + 2 * table_plane_size] = ((yval + 43) / 85) << bbase;
      yb += cy;
}}
