#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * const pixels, int i, const int linesize, const int row,
    const int w)
{
  IACA_START for (i = 0; i < w && pixels[row * linesize + i * 4 + 0] == 0; i++);
  IACA_END
}
