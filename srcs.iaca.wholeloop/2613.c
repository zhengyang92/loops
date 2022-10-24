#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int width, uint8_t * dst, const uint8_t * src, uint32_t x)
{
  IACA_START for (x = 0; x < width; x++)
    {
      dst[x] = *src;
      src += 2;
     } IACA_END
}
