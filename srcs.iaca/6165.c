#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * src, uint8_t * dst, int i, int stride)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      dst[0] += src[0];
      dst[1] += src[1];
      dst[2] += src[2];
      dst[3] += src[3];
      dst[4] += src[4];
      dst[5] += src[5];
      dst[6] += src[6];
      dst[7] += src[7];
      dst += stride;
      src += 8;
     } IACA_END
}
