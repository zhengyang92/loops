#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int mode_list[128], int coef_list[128], int i, int ccoef, int list_end)
{
  for (i = 0; i < 3; i++)
     { IACA_START
      ccoef += 4;
      coef_list[list_end] = ccoef;
      mode_list[list_end++] = 2;
     } IACA_END
}
