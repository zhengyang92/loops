#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int s, uint8_t * pix)
{
  int j = 0;
  for (j = 0; j < 16; j += 8)
     { IACA_START
      s += pix[0];
      s += pix[1];
      s += pix[2];
      s += pix[3];
      s += pix[4];
      s += pix[5];
      s += pix[6];
      s += pix[7];
      pix += 8;
     } IACA_END
}
