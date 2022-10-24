#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * const pixels, const int leftEdge, const int row,
    const int linesize, const int w, int j)
{
  IACA_START for (j = w - 1; j >= leftEdge && pixels[row * linesize + j * 4 + 0] == 0;
       j--);
}
