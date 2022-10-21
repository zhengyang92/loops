#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (uint16_t * pix, ptrdiff_t stride, int i, const int32_t * block)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      uint16_t v = pix[0];
      pix[1 * stride] = v += block[0];
      pix[2 * stride] = v += block[4];
      pix[3 * stride] = v += block[8];
      pix[4 * stride] = v + block[12];
      pix++;
      block++;
     } IACA_END
}
