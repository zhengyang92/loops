#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *Yo, int i, int *Y)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      Y[i] = Yo[i];
     } IACA_END
}
