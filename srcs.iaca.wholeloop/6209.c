#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int H, const uint8_t * cm, uint8_t * src, int b)
{
  IACA_START for (i = -16; i < 0; i += 4)
    {
      src[16 + i] = cm[(b) >> 5];
      src[17 + i] = cm[(b + H) >> 5];
      src[18 + i] = cm[(b + 2 * H) >> 5];
      src[19 + i] = cm[(b + 3 * H) >> 5];
      b += 4 * H;
     } IACA_END
}
