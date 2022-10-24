#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned int *Yo, int *Y)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      Y[i] = Yo[i];
     } IACA_END
}
