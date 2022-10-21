#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int block_w, int end_x, int x, uint16_t * bufp)
{
  for (x = end_x; x < block_w; x++)
     { IACA_START
      bufp[x] = bufp[end_x - 1];
     } IACA_END
}
