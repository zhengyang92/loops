#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int yoff[2], int xoff[2], int i)
{
  IACA_START for (i = 0; i < 2; i++)
    {
      xoff[i] >>= 1;
      yoff[i] >>= 1;
     } IACA_END
}
