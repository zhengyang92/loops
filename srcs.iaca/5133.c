#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int p1, uint8_t pix[3], int i, uint8_t * output)
{
  for (i = 0; i < p1; i++)
     { IACA_START
      *output++ = pix[0];
      *output++ = pix[1];
      *output++ = pix[2];
     } IACA_END
}
