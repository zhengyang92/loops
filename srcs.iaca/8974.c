#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int width, uint16_t * src_line, int x, uint16_t ** dst, int shift)
{
  for (x = 0; x < width; x++)
     { IACA_START
      dst[0][x] = *src_line++ >> shift;
      dst[1][x] = *src_line++ >> shift;
      dst[2][x] = *src_line++ >> shift;
     } IACA_END
}
