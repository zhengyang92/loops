#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *Yo, int *last, int i, int *Y)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      Y[i] = Yo[i];
      last[i] = Yo[i];
     } IACA_END
}
