#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t pred, const uint8_t * in, uint8_t * out)
{
  for (i = 0; i < width; ++i)
     { IACA_START
      out[i] = pred + in[i];
      pred = out[i];
     } IACA_END
}
