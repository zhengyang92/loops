#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int count, float *buf, int switch_point, float *out, float *in,
    float ff_mdct_win_float[8][40], int j, int block_type)
{
  for (; j < count; j++)
     { IACA_START
      int win_idx = (switch_point && j < 2) ? 0 : block_type;
      float *win = ff_mdct_win_float[win_idx + (4 & -(j & 1))];
      ff_imdct36_float_sse2 (out, buf, in, win);
      in += 18;
      buf++;
      out++;
} IACA_END }
