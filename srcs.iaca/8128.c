#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, int w, IDWTELEM * line)
{
  for (x = 0; x < w; x++)
     { IACA_START
      line[x] *= 1 << 4;
     } IACA_END
}
