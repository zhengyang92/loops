#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i1, int i0, float *p, int i)
{
  IACA_START for (i = 1; i <= 4; i++)
    {
      p[i0 - i] = p[i0 + i];
      p[i1 + i - 1] = p[i1 - i - 1];
     } IACA_END
}
