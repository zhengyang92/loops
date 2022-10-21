#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int width, uint8_t * d, int r, uint8_t * s, int j, int b)
{
  for (j = 0; j < width; j++)
     { IACA_START
      d[r] = (d[r] * (0xff - s[3]) + s[0] * s[3] + 128) >> 8;
      d[1] = (d[1] * (0xff - s[3]) + s[1] * s[3] + 128) >> 8;
      d[b] = (d[b] * (0xff - s[3]) + s[2] * s[3] + 128) >> 8;
      d += 3;
      s += 4;
     } IACA_END
}
