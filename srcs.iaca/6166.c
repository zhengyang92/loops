#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;

int
fn (int stride, uint16_t * dst, int i, int32_t * src)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      dst[0] += src[0];
      dst[1] += src[1];
      dst[2] += src[2];
      dst[3] += src[3];
      dst += stride;
      src += 4;
     } IACA_END
}
