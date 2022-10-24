#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int mode_list[128], int coef_list[128], int i, int ccoef, int list_end)
{
  IACA_START for (i = 0; i < 3; i++)
    {
      ccoef += 4;
      coef_list[list_end] = ccoef;
      mode_list[list_end++] = 2;
     } IACA_END
}
