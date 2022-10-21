#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (ptrdiff_t stride, const int16_t * block, uint8_t * pix, int i)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      uint8_t v = pix[-1];
      pix[0] = v += block[0];
      pix[1] = v += block[1];
      pix[2] = v += block[2];
      pix[3] = v += block[3];
      pix[4] = v += block[4];
      pix[5] = v += block[5];
      pix[6] = v += block[6];
      pix[7] = v + block[7];
      pix += stride;
      block += 8;
     } IACA_END
}
