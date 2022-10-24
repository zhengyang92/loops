#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * b3, IDWTELEM * b2, int x, int width, IDWTELEM * b1,
    IDWTELEM * b0)
{
  IACA_START for (x = 0; x < width; x++)
    {
      b2[x] -= (b1[x] + b3[x] + 2) >> 2;
      b1[x] += (b0[x] + b2[x]) >> 1;
     } IACA_END
}
