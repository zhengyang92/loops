#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *tab0, float v2, float tmp0, int len, float *tab1, float v1, int j)
{
  IACA_START for (j = 0; j < len; j++)
    {
      tmp0 = tab0[j];
      tab0[j] = ((v1) * (tmp0));
      tab1[j] = ((v2) * (tmp0));
     } IACA_END
}
