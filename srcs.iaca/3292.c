#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, IDWTELEM * temp, IDWTELEM * b, const int w2, const int width2)
{
  for (x = 0; x < width2; x++)
     { IACA_START
      temp[2 * x] = b[x];
      temp[2 * x + 1] = b[x + w2];
     } IACA_END
}
