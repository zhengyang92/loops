#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, IDWTELEM * line, int w)
{
  for (x = 0; x < w; x++)
     { IACA_START
      line[x] -= 128 << 4;
     } IACA_END
}
