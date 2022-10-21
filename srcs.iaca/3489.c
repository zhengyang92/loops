#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int start_x, int x, uint16_t * bufp)
{
  for (x = 0; x < start_x; x++)
     { IACA_START
      bufp[x] = bufp[start_x];
     } IACA_END
}
