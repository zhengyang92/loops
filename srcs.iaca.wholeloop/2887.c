#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int count, int *in, int switch_point, int ff_mdct_win_fixed[8][40],
    int *out, int *buf, int j, int block_type)
{
  IACA_START for (j = 0; j < count; j++)
    {
      int win_idx = (switch_point && j < 2) ? 0 : block_type;
      int *win = ff_mdct_win_fixed[win_idx + (4 & -(j & 1))];
      imdct36 (out, buf, in, win);
      in += 18;
      buf += ((j & 3) != 3 ? 1 : (72 - 3));
      out++;
}IACA_END}
