#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, IDWTELEM * buf, int y, int w)
{
  for (x = 0; x < w; x++)
     { IACA_START
      buf[x + y * w] -= 128 << 4;
     } IACA_END
}
