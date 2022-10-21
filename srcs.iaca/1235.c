#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t histogram[6], int k)
{
  int min = 255;
  for (k = 0; k < 4; k++)
     { IACA_START
      min = ((min) > (histogram[k]) ? (histogram[k]) : (min));
     } IACA_END
}
