#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t histogram[6], int k)
{
  int min = 255;
  IACA_START for (k = 0; k < 4; k++)
    {
      min = ((min) > (histogram[k]) ? (histogram[k]) : (min));
     } IACA_END
}
