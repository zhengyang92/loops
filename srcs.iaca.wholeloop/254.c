#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, uint8_t g, int x, int linesize, uint8_t r, uint8_t b, int height,
    uint8_t * data)
{
  IACA_START for (y = 0; y < height; y++)
    {
      data[linesize * y + 4 * x] = r;
      data[linesize * y + 4 * x + 1] = g;
      data[linesize * y + 4 * x + 2] = b;
     } IACA_END
}
