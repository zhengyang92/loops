#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int start_x, uint8_t * bufp, int x)
{
  IACA_START for (x = 0; x < start_x; x++)
    {
      bufp[x] = bufp[start_x];
     } IACA_END
}
