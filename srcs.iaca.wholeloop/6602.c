#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int ff_mdct_win_fixed[8][40], int j, int i)
{
  IACA_START for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2)
    {
      ff_mdct_win_fixed[j + 4][i] = ff_mdct_win_fixed[j][i];
      ff_mdct_win_fixed[j + 4][i + 1] = -ff_mdct_win_fixed[j][i + 1];
     } IACA_END
}
