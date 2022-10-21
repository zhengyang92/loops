#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, const uint8_t * msrc, int x, const uint8_t * asrc, uint8_t * dst)
{
  for (x = 0; x < w; x++)
     { IACA_START
      dst[x] = ((msrc[x] * (((asrc[x] >> 1) & 1) + asrc[x])) + 128) >> 8;
     } IACA_END
}
