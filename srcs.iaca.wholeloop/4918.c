#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, const int16_t * block, uint8_t * pix, int i)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      uint8_t v = pix[0];
      pix[1 * stride] = v += block[0];
      pix[2 * stride] = v += block[8];
      pix[3 * stride] = v += block[16];
      pix[4 * stride] = v += block[24];
      pix[5 * stride] = v += block[32];
      pix[6 * stride] = v += block[40];
      pix[7 * stride] = v += block[48];
      pix[8 * stride] = v + block[56];
      pix++;
      block++;
     } IACA_END
}
