#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;

int
fn (int v, uint16_t * dc, int width, int x, int r, uint32_t dc_factor)
{
  for (; x < width / 2; x++)
     { IACA_START
      v += dc[x] - dc[x - r];
      dc[x - r] = v * dc_factor >> 16;
     } IACA_END
}
