#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * srcU, uint8_t * srcV, int k, int i)
{
  for (i = 0; i < k; i++)
     { IACA_START
      srcU[i] = ((srcU[i] - 128) >> 1) + 128;
      srcV[i] = ((srcV[i] - 128) >> 1) + 128;
     } IACA_END
}
