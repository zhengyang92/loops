#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * output, uint8_t pix[3], int i, int p1)
{
  for (i = 0; i < p1; i++)
     { IACA_START
      *output++ = pix[0];
      *output++ = pix[1];
      *output++ = pix[2];
     } IACA_END
}
