#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, uint16_t * src_line, int width, uint16_t ** dst, int shift)
{
  IACA_START for (x = 0; x < width; x++)
    {
      dst[0][x] = *src_line++ >> shift;
      dst[1][x] = *src_line++ >> shift;
      dst[2][x] = *src_line++ >> shift;
      dst[3][x] = 0xFFFF;
     } IACA_END
}
