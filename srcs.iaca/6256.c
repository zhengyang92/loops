#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;
typedef __int32_t int32_t;

int
fn (uint16_t * pix, ptrdiff_t stride, int i, const int32_t * block)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      uint16_t v = pix[-1];
      pix[0] = v += block[0];
      pix[1] = v += block[1];
      pix[2] = v += block[2];
      pix[3] = v + block[3];
      pix += stride;
      block += 4;
     } IACA_END
}
