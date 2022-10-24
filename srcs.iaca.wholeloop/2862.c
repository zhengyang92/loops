#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *tab0, unsigned int tmp0, int *tab1, unsigned int tmp1)
{
  IACA_START for (i = 0; i < 576; i++)
    {
      tmp0 = tab0[i];
      tmp1 = tab1[i];
      tab0[i] = tmp0 + tmp1;
      tab1[i] = tmp0 - tmp1;
     } IACA_END
}
