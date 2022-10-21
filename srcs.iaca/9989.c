#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * v, int n, const uint8_t * u, const uint8_t * y, int len,
    uint8_t * dst)
{
  for (; n < len; ++n)
     { IACA_START
      VP8YuvToRgba (y[0], u[0], v[0], dst);
      dst += 4;
      y += 1;
      u += (n & 1);
      v += (n & 1);
     } IACA_END
}
