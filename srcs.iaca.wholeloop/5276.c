#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, IDWTELEM * line, int w)
{
  IACA_START for (x = 0; x < w; x++)
    {
      line[x] -= 128 << 4;
     } IACA_END
}
