#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int width, uint8_t * dst, uint8_t * src)
{
  IACA_START for (int x = 0; x < width; x++)
    {
      dst[x] = (uint8_t) ((src[x] >> 1) + (src[x + 1] >> 1));
}IACA_END}
