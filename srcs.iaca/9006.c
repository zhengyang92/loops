#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint32_t uint32_t;

int
fn (int bbase, const int table_plane_size, int i, int needAlpha, int gbase,
    int64_t cy, int rbase, uint32_t * y_table32, int abase, int64_t yb)
{
  for (i = 0; i < table_plane_size; i++)
     { IACA_START
      unsigned yval = av_clip_uint8_c ((yb + 0x8000) >> 16);
      y_table32[i] = (yval << rbase) + (needAlpha ? 0 : (255u << abase));
      y_table32[i + table_plane_size] = yval << gbase;
      y_table32[i + 2 * table_plane_size] = yval << bbase;
      yb += cy;
} IACA_END }
