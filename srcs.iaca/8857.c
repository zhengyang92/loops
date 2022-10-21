#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, int width, IDWTELEM * temp, IDWTELEM * b)
{
  for (x = 2; x < width - 1; x += 2)
     { IACA_START
      b[x] = temp[x] + ((4 * temp[x] + temp[x - 1] + temp[x + 1] + 8) >> 4);
      b[x - 1] = temp[x - 1] + ((3 * (b[x - 2] + b[x])) >> 1);
     } IACA_END
}
