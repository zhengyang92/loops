#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int width, IDWTELEM * temp, int x, IDWTELEM * b, const int w2)
{
  IACA_START for (x = 1; x < (width >> 1); x++)
    {
      temp[2 * x] = b[x] - ((3 * (b[x + w2 - 1] + b[x + w2]) + 4) >> 3);
      temp[2 * x - 1] = b[x + w2 - 1] - temp[2 * x - 2] - temp[2 * x];
     } IACA_END
}
