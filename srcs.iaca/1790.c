#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * band, int j, int width)
{
  for (j = 1; j < width; j++)
     { IACA_START
      band[j] += band[j - 1];
     } IACA_END
}
