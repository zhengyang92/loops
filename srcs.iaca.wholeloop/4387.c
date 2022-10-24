#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w0, int x, unsigned int *cchange, uint16_t * d, const uint16_t * i)
{
  IACA_START for (x = 0; x < w0; x++)
    {
      d[x] = cchange[i[x]];
     } IACA_END
}
