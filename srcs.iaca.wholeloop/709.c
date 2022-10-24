#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, uint8_t * buf, int h, int sy, int sx, int color, int stride)
{
  IACA_START for (int y = sy; y < sy + h; y++)
    {
      buf[sx] = color;
      buf[sx + w - 1] = color;
      buf += stride;
}IACA_END}
