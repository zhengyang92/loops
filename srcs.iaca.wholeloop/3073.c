#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int size, int bpp, uint8_t * dst, uint8_t * src)
{
  IACA_START for (; i < size; i++)
    {
      dst[i] = ((dst[i - bpp]) + (src[i]));
     } IACA_END
}
