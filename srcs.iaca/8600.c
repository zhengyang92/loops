#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint8_t * src, uint16_t * dst2, uint16_t * dst1, int i)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      dst1[i] = dst2[i] = src[i] * 0x0101;
     } IACA_END
}
