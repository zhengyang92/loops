#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float ff_mdct_win_float[8][40])
{
  for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2)
     { IACA_START
      ff_mdct_win_float[j + 4][i] = ff_mdct_win_float[j][i];
      ff_mdct_win_float[j + 4][i + 1] = -ff_mdct_win_float[j][i + 1];
     } IACA_END
}
