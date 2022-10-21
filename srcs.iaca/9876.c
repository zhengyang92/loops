#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, int length, uint8_t * dst, int i)
{
  for (i <<= 2; i < length; ++i)
     { IACA_START
      dst[i] = src[i];
     } IACA_END
}
